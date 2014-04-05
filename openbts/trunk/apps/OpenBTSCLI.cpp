                                      /*
* Copyright 2011 Range Networks, Inc.
*
* This software is distributed under the terms of the GNU Affero Public License.
* See the COPYING file in the main directory for details.
*
* This use of this software may be subject to additional restrictions.
* See the LEGAL file in the main directory for details.

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Affero General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>   

#ifdef HAVE_LIBREADLINE
#  include <readline/readline.h>
#  include <readline/history.h>
#endif

#define DEFAULT_CMD_PATH "/var/run/command"
#define DEFAULT_RSP_PATH "./response"

// For the lock-out mechanism
// 3600 secs = 1 hr
#define LOCKOUTPERIOD 3600

#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// for crypto++ (login)
#include "cryptopp/hex.h"
#include "cryptopp/sha.h"
#include "cryptopp/cryptlib.h"
#include <termios.h>
#include <unistd.h>

using namespace std;
using namespace CryptoPP;

// for database access
#include "sqlite3.h"
#define DB "openbtsusers.db"

bool isOpenDB1 = false; // for the opebtsusers.db
sqlite3 *dbfile;

// global variable
int currentuserid = 1;

// FUNCTION DECLARATIONS----------------------------------------
bool ConnectDB(sqlite3**, const char*, bool*);
void DisconnectDB(bool, sqlite3**);
bool authenticateuser();
string sha256hash(string);
void echo(bool);
bool logincheck(string);
string passcheck(string);
int resetcounter(string);
int insertactiveuser(int, string);
int deleteactiveuser();
void addHistory (string);
int updateloginhistory(string, bool);
string getStringDate(string);
// END FUNCTION DECLARATIONS -------------------------------

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{
	// open database for logging in
	bool isOpenDB = false;
	isOpenDB = ConnectDB(&dbfile, DB, &isOpenDB1);
	if ( isOpenDB )
		cout << "DB Connected Successfully" << endl;
	else cout << "DB Connection Failed " << endl;

	if(authenticateuser() == false)
		return 0;

	// disconnect database after using for logging in
	DisconnectDB(isOpenDB1, &dbfile);

	const char* cmdPath = DEFAULT_CMD_PATH;
	if (argc!=1) {
		cmdPath = argv[1];
	}

	char rspPath[200];
	sprintf(rspPath,"/tmp/OpenBTS.console.%d.%8lx",getpid(),time(NULL));

	printf("command socket path is %s\n", cmdPath);

	char prompt[strlen(cmdPath) + 20];
	sprintf(prompt,"OpenBTS> ");

	// the socket
	int sock = socket(AF_UNIX,SOCK_DGRAM,0);
	if (sock<0) {
		perror("opening datagram socket");
		exit(1);
	}

	// destination address
	struct sockaddr_un cmdSockName;
	cmdSockName.sun_family = AF_UNIX;
	strcpy(cmdSockName.sun_path,cmdPath);

	// locally bound address
	struct sockaddr_un rspSockName;
	rspSockName.sun_family = AF_UNIX;
	char rmcmd[strlen(rspPath)+5];
	sprintf(rmcmd,"rm %s",rspPath);
	system(rmcmd);
	strcpy(rspSockName.sun_path,rspPath);
	if (bind(sock, (struct sockaddr *) &rspSockName, sizeof(struct sockaddr_un))) {
		perror("binding name to datagram socket");
		exit(1);
	}
	printf("response socket bound to %s\n",rspSockName.sun_path);

#ifdef HAVE_LIBREADLINE
	// start console
	using_history();

	static const char * const history_file_name = "/.openbts_history";
	char *history_name = 0;
	char *home_dir = getenv("HOME");

	if(home_dir) {
		size_t home_dir_len = strlen(home_dir);
		size_t history_file_len = strlen(history_file_name);
		size_t history_len = home_dir_len + history_file_len + 1;
		if(history_len > home_dir_len) {
			if(!(history_name = (char *)malloc(history_len))) {
				perror("malloc failed");
				exit(2);
			}
			memcpy(history_name, home_dir, home_dir_len);
			memcpy(history_name + home_dir_len, history_file_name,
			   history_file_len + 1);
			read_history(history_name);
		}
	}

	printf("readline installed\n");
#endif

	printf("Remote Interface Ready.\nType:\n \"help\" to see commands,\n \"version\" for version information,\n \"notices\" for licensing information.\n\"quit\" to exit console interface\n");


	while (1) {
#ifdef HAVE_LIBREADLINE
		char *cmd = readline(prompt);
		if (!cmd) break;
		if (*cmd) add_history(cmd);
#else // HAVE_LIBREADLINE
		printf("%s",prompt);
		fflush(stdout);
		char *inbuf = (char*)malloc(200);
		char *cmd = fgets(inbuf,199,stdin);
		if (!cmd) continue;
		// strip trailing CR
		cmd[strlen(cmd)-1] = '\0';
#endif

		// local quit?
		if (strcmp(cmd,"quit")==0) {
			printf("closing remote console\n");
			break;
		}
		else if(strcmp(cmd,"INVALIDCOMMAND")==0) {
			printf("Invalid Command\n");
		}
		else {
			if (sendto(sock,cmd,strlen(cmd)+1,0,(struct sockaddr*)&cmdSockName,sizeof(cmdSockName))<0) {
				perror("sending datagram");
				printf("Is the remote application running?\n");
				continue;
			}
			free(cmd);
			const int bufsz = 10000;
			char resbuf[bufsz];
			int nread = recv(sock,resbuf,bufsz-1,0);
			if (nread<0) {
				perror("receiving response");
				continue;
			}
			resbuf[nread] = '\0';
			printf("%s\n",resbuf);
			if (nread==(bufsz-1)) printf("(response truncated at %d characters)\n",nread);
		}
	}

#ifdef HAVE_LIBREADLINE
	if(history_name) {
		int e = write_history(history_name);
		if(e) {
			fprintf(stderr, "error: history: %s\n", strerror(e));
		}
		free(history_name);
		history_name = 0;
	}
#endif


	close(sock);
}

void addHistory (string desc) {
	std::stringstream strm;
	strm << "insert into historylogs(userid, description) values(" << currentuserid << ", '" << desc << "');";

	string s = strm.str();
	char *str = &s[0];
	sqlite3_stmt *statement;
	int result;
	char *query = str;
	if(sqlite3_prepare(dbfile,query,-1,&statement,0)==SQLITE_OK)
	{
		int res=sqlite3_step(statement);
		result=res;
		sqlite3_finalize(statement);
	}
}

bool ConnectDB (sqlite3 **dbfile, const char* database, bool *isOpenDB)
{
    if ( sqlite3_open(database, dbfile) == SQLITE_OK )
    {
        *isOpenDB = true;
        return true;
    }
    return false;
}


void DisconnectDB (bool isOpenDB, sqlite3 **dbfile)
{
	if ( isOpenDB == true ) 
	{
		sqlite3_close(*dbfile);
	}
}

bool authenticateuser()
{
	string login;
	string password;
	string userid;
	sqlite3_stmt *statement;
	int authtag = 0;	
	bool check = false;

	while(authtag == 0) {

		while(check == false)
		{
			cout << "Please Enter Your Username: ";
			getline(cin, login);	
			cout << "Please Enter Your Password: ";
			echo( false );
			getline(cin, password);
			echo ( true );
			cout << endl;
			password = passcheck(password);
			check = logincheck(login);
			if(check == false)
			{
				cout << "Authentication Failed. Please try again" << endl;
			}
		}
		string q = "select * from users where login = '" + login + "';";
		const char *query = q.c_str();
		if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
		{
			int ctotal = sqlite3_column_count(statement);
			int res = 0;
	
			res = sqlite3_step(statement);
			if ( res == SQLITE_DONE )	
			{
				check = false;
				cout << "Username does not exist." << endl;
			}
			else {
				int userid = atoi((char*)sqlite3_column_text(statement, 0));
				string insertedon = (char*)sqlite3_column_text(statement, 3);
				string hashedpass = sha256hash(sha256hash(password) + insertedon);
				string systempass = (char*)sqlite3_column_text(statement, 2);
				int failcnt = atoi((char*)(sqlite3_column_text(statement, 6)));
				string successlogin = (char*)sqlite3_column_text(statement, 4);
				string faillogin = (char*)sqlite3_column_text(statement, 5);

				//************************************************************
				//CHECK IF n secs has passed after lastfaillogin START
				//if yes, reset: resetcounter

				time_t now;
  				time(&now);
				int timedifference = now - atoi(faillogin.c_str()); // why not faillogin?

				if(timedifference >= LOCKOUTPERIOD) {
					resetcounter(login);
					failcnt = 0;
				}

				//END
				// ************************************************************


				if(failcnt < 3) {
					if(systempass == hashedpass) {	
						authtag = 1;
						currentuserid = userid;
						if(successlogin.length() == 0)
							cout << endl << "No successful logins before.";
						else {
							string successLog = getStringDate(successlogin);
							cout << endl << "Your last successful login was on " << successLog << ".";
						}
						if(faillogin.length() == 0)
							cout << endl << "No unsuccessful logins before." << endl << endl;
						else {
							string failedLog = getStringDate(faillogin);
							cout << endl << "Your last unsuccesful login was on " << failedLog << "." << endl << endl;
						}
						
						char *shortcode = (char*)sqlite3_column_text(statement, 7);

						if (shortcode == NULL)
							shortcode = (char*) " ";

						updateloginhistory(login, true);
						deleteactiveuser();
						insertactiveuser(userid, shortcode);

						addHistory("User has logged in.");
					} else {
						check = false;
						cout << "Authentication Failed. Please try again." << endl;
						updateloginhistory(login, false);
					}
				} else {
					cout << "Account has been locked. You may try again after " << (LOCKOUTPERIOD - timedifference) << " seconds." << endl;
					return false;
				}
				sqlite3_finalize(statement);
			}
		}
	}
	return true;
}

string sha256hash(string data)
{
	byte const* pbData = (byte*) data.data();
    unsigned int nDataLen = data.size();
    byte abDigest[SHA256::DIGESTSIZE];

    SHA256().CalculateDigest(abDigest, pbData, nDataLen);
	
	string encoded; 
	HexEncoder encoder; 
	encoder.Put(abDigest, sizeof(abDigest)); 
	encoder.MessageEnd(); 
	word64 size = encoder.MaxRetrievable(); 
	if(size) 
	{ 
		encoded.resize(size); 
		encoder.Get((byte*)encoded.data(), encoded.size()); 
	} 
	
	return encoded;
}

void echo( bool on = true )
{
  struct termios settings;
  tcgetattr( STDIN_FILENO, &settings );
  settings.c_lflag = on
                   ? (settings.c_lflag |   ECHO )
                   : (settings.c_lflag & ~(ECHO));
  tcsetattr( STDIN_FILENO, TCSANOW, &settings );
}

int resetcounter(string login)
{
	
	std::stringstream strm;	

	strm << "update users set failcounter = 0 where login = '"  << login << "';";

	string s = strm.str();

	char *str = &s[0];
	
	sqlite3_stmt *statement;
	int result;
	char *query = str;	
	
	{
		if(sqlite3_prepare(dbfile,query,-1,&statement,0)==SQLITE_OK)
		{
			int res=sqlite3_step(statement);
			result=res;
			sqlite3_finalize(statement);
		}
		return result;
	}

	return 0;
}

int updateloginhistory(string login, bool success)
{
	std::stringstream strm;	
	
	if(success) {
		strm << "update users set lastsuccessfullogin = ((julianday('now') - 2440587.5)*86400.0), failcounter = 0 where login = '"  << login << "';";
	} else {
		strm << "update users set lastfailedlogin = ((julianday('now') - 2440587.5)*86400.0) , failcounter = failcounter + 1 where login = '"  << login << "';";
	}

	
	string s = strm.str();

	char *str = &s[0];
	
	sqlite3_stmt *statement;
	int result;
	char *query = str;	
	
	if(sqlite3_prepare(dbfile,query,-1,&statement,0)==SQLITE_OK)
	{
		int res=sqlite3_step(statement);
		result=res;
		sqlite3_finalize(statement);
	}
	return result;
}

bool logincheck(string input)
{
    int ctr;
    for(ctr = 0; ctr < input.length(); ctr++)
    {
        if(isalnum(input[ctr]) == false)
        {
            if(input[ctr] != '.' && input[ctr] != '_')
            {
                return false;
            }
        }
    }
    return true;
}

string passcheck(string input)
{
    int ctr = 0;
    while(ctr < input.length())
    {
        if(input[ctr] == '\'')
        {
            input.insert(ctr, "'");
            ctr++;
        }
        ctr++;
    }
    return input;
}

string getStringDate(string unixTimestamp)
{
	sqlite3_stmt *statement;
	string q = "select datetime(" + unixTimestamp + ", 'unixepoch', 'localtime');";
	const char *query = q.c_str();
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int res = 0;
		res = sqlite3_step(statement);
		if ( res == SQLITE_DONE )	
		{
			return "Invalid date.";
		}
		char *temp = (char*)sqlite3_column_text(statement, 0);
		sqlite3_finalize(statement);
		return temp;
	}
}

int deleteactiveuser() {
	char *err = 0;

	const char *query =  "DELETE FROM activeuser;";
	int rc = sqlite3_exec(dbfile, query, callback, 0, &err);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}
	return 0;
}

int insertactiveuser(int userid, string shortcode) {
	std::stringstream strm;	

	if(shortcode == " ") {
		strm << "insert into activeuser(userid) values(" << userid << ");"; 
	} else {
		strm << "insert into activeuser(userid, shortcode) values(" << userid << ", '" << shortcode << "');"; 
	}

	string s = strm.str();

	char *str = &s[0];
	
	sqlite3_stmt *statement;
	int result;
	char *query = str;	
	{
		if(sqlite3_prepare(dbfile,query,-1,&statement,0)==SQLITE_OK)
		{
			int res=sqlite3_step(statement);
			result=res;
			sqlite3_finalize(statement);
		}
		return result;
	}

	return 0;
}
