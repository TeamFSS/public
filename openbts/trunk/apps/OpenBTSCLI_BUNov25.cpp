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

//#include <config.h>
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
#define LOCKOUTPERIOD 3600

#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// for crypto++
#include "cryptopp/hex.h"
#include "cryptopp/sha.h"
#include "cryptopp/cryptlib.h"
#include <termios.h>
#include <unistd.h>

//#include "uidCLI.h"

using namespace std;
using namespace CryptoPP;

#include "sqlite3.h"
#define DB "openbtsusers.db"

bool isOpenDB1 = false; // for the opebtsusers.db
sqlite3 *dbfile;

string currentusername= "";
string currenthashedpassword = "";
int currentuserid = 1;

int privilege = -1;

bool ConnectDB(sqlite3**, const char*, bool*);
void DisconnectDB(bool, sqlite3**);
bool authenticateuser();
string sha256hash(string);
void echo(bool);
bool logincheck(string);
string passcheck(string);
//char *getshortcodefromdb();

//add update user
int updateuseropenbts(string, string, bool) ;
int pseudoupdate(string);
string getinsertedon(string);
int insertnewuseropenbts(string, string);
int updateloginhistory(string, bool);
string getStringDate(string);

//update rates
bool isValid(string);

bool userexists(string);
int resetcounter(string);

int updateshortcode_checkexists(string);
int updateshortcode_actual(string, string);
string getcurrentshortcodes(string);

int saveactiveuser(int, string, int);
int insertactiveuser(int, string, int);
int deleteactiveuser();
int getPrivilege();
int editprivilege(bool, string);

int ismodulerestricted(string);
bool userhaspermissions(int, int);

void addHistory (string);

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
	bool isOpenDB = false;
	isOpenDB = ConnectDB(&dbfile, DB, &isOpenDB1);
	if ( isOpenDB ) 
		cout << "DB Connected Successfully" << endl;
	else cout << "DB Connection Failed " << endl;

	if(authenticateuser() == false)
		return 0;

	DisconnectDB(isOpenDB1, &dbfile);

	if(isOpenDB1)
		cout << "OPEN";
	else
		cout << "CLOSE";

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

		// check if file exists
		string line;
		ifstream actionLog("actionLog.txt");
		if (actionLog.is_open()) {
			// file exists
			// read from file
			getline(actionLog, line);
			actionLog.close();

			addHistory(line);

			// destroy file
			remove("actionLog.txt");
		}

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

		//ADELEN
		//CHECK IF CMD EXISTS AS modulename in MODULES
		int moduleid = ismodulerestricted(cmd);
		if(moduleid != -1) {
			//IF YES, get moduleid then check if user has permissions via userpermissions
			if(userhaspermissions(currentuserid, moduleid) == false)
				strcpy(cmd, "INVALIDCOMMAND");
		}

		// local quit?
		if (strcmp(cmd,"quit")==0) {
			deleteactiveuser();
			printf("closing remote console\n");
			addHistory("User has logged-out.");
			break;
		}
		else if(strcmp(cmd,"INVALIDCOMMAND")==0) {
			printf("Invalid Command\n");
		}
		//USER WANTS TO ADD NEW USER START
		else if (strcmp(cmd,"add_user")==0) {
			string newuserlogin;
			string newuserpassword;
			string confirmpass;
			int privilege = 0;

			// check privilege
			privilege = getPrivilege();

			// privilege has to be '1' to add user
			if (privilege == 1) {
				while(1) {
					cout << "Enter login for new user: ";
					//cin >> newuserlogin;
					getline(cin, newuserlogin);
					if(logincheck(newuserlogin) == false)
					{
						cout << "Invalid login" << endl;
					}
					else
					{	
						if(userexists(newuserlogin)) {
						cout << "Username already used." << endl;				
						} else {
							break;
						}
					}
				}
				while(1) {
					cout << "Enter password for new user: ";
					//cin >> newuserpassword;
					echo(false);
					getline(cin, newuserpassword);
					echo(true);
					cout << endl;
					newuserpassword = passcheck(newuserpassword);
					cout << "Confirm password for new user: ";
					//cin >> confirmpass;
					echo(false);
					getline(cin, confirmpass);
					echo(true);
					cout << endl;
					confirmpass = passcheck(confirmpass);
					if(newuserpassword == confirmpass) {
						break;
					} else {
						cout << "The passwords don't match." << endl;
					}
				}
				insertnewuseropenbts(newuserlogin, newuserpassword);

				string desc = "User " + newuserlogin + " has been added to the system!";
				cout << desc << endl;
				addHistory(desc);
			}
			else
				cout << "Cannot add user. User has to have admin privileges to add user." << endl;
		}
		//USER WANTS TO ADD NEW USER END

		else if(strcmp(cmd,"mod_priv")==0) {	
			if(getPrivilege() == 1) {
				string mp_username = "";
				string mp_privilege = "";
				cout << "Username of account you want to change: ";
				getline(cin, mp_username);
				while(userexists(mp_username) == false) {
					cout << "Username of account you want to change: ";
					getline(cin, mp_username);
				}
				while(mp_privilege != "0" && mp_privilege != "1") {
					cout << "Enter privilege (0/1): ";
					getline(cin, mp_privilege);
				}
				if(mp_privilege == "1") {
					editprivilege(true, mp_username);
				} else {
					editprivilege(false, mp_username);
				}
			} else {
				cout << "Command Unavailable." << endl;
			}
		}


		//USER WANTS TO UPDATE USER START
		 else if (strcmp(cmd,"update_user")==0) {
			string newlogin = currentusername;
			string newpassword;
			string confirmpass;
			string currentpassword;
			while(1) {
				while(1) {
					cout << "Enter your current password: ";
					//cin >> currentpassword;
					echo(false);
					getline(cin, currentpassword);
					echo(true);
					cout << endl;
					currentpassword = passcheck(currentpassword);
					string insertedon = getinsertedon(currentusername);
					if(currenthashedpassword == sha256hash(sha256hash(currentpassword) + insertedon)) {
						break;
					}
					cout << "Wrong password. Try again." << endl;
				}
				cout << "Enter new password: ";
				//cin >> newpassword;
				echo(false);
				getline(cin, newpassword);
				echo(true);
				cout << endl;
				newpassword = passcheck(newpassword);
				cout << "Confirm new password: ";
				//cin >> confirmpass;
				echo(false);
				getline(cin, confirmpass);
				echo(true);
				cout << endl;
				confirmpass = passcheck(confirmpass);
				if(newpassword == confirmpass) {
					break;
				} else {
					cout << "The passwords don't match." << endl;
				}
			}
			pseudoupdate(newlogin);
			updateuseropenbts(newlogin, newpassword, true);

			string desc = "Account " + newlogin + " has been updated!";
			cout << desc << endl;
			addHistory(desc);
		}
		//USER WANTS TO UPDATE USER END

		//USER WANTS TO ADD/MODIFY SHORTCODES START

		else if (strcmp(cmd,"shortcodes")==0) {
			string sc_login = "";
			string sc_shortcode = "";
			string sc_option = "";
			string sc_newshortcode = "";
			int sc_tag = -1;
			if(privilege == 1) {
				cout << "Username whose shortcode you wish to modify?: ";
				getline(cin, sc_login);
				sc_tag = updateshortcode_checkexists(sc_login);
				if(sc_tag == 0){
					cout << "User does not exist.";
				} else {
					cout << "Current shortcode: ";
					string sc_current = getcurrentshortcodes(sc_login);
					cout << sc_current << endl;
					cout << "Do you want to change? (y for yes)";
					getline(cin, sc_option);
					if(sc_option == "y") {
						cout << "New shortcode for this account: ";
						getline(cin, sc_newshortcode);
						updateshortcode_actual(sc_login, sc_newshortcode);
						string desc = "Shortcode for " + sc_login + " has been updated to " + sc_newshortcode + ".";
						cout << desc << endl;
						addHistory(desc);
					}
				}
			} else {	
				cout << "Sorry. Command unavailable.";
			}
		}
		//USER WANTS TO ADD/MODIFY SHORTCODES END


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
		cout << "CC";
		cout << "dddd";
		cout << sqlite3_close(*dbfile);
		cout << "ss";
		if(sqlite3_close(*dbfile) == SQLITE_OK)
			cout << "OK";
		else
			cout << "dd";
	}
}

int updateshortcode_checkexists(string login) {
	sqlite3_stmt *statement;
	string q = "select * from users where login = '" + login + "';";
	const char *query = q.c_str();
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int ctotal = sqlite3_column_count(statement);
		int res = 0;

		res = sqlite3_step(statement);
		if ( res == SQLITE_DONE )	
		{
			cout << "User does not exist." << endl;
			return 0;
		} 
	}
	return 1;
}

string getcurrentshortcodes(string login) {
	sqlite3_stmt *statement;
	string q = "select shortcode from users where login = '" + login + "';";
	const char *query = q.c_str();
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int ctotal = sqlite3_column_count(statement);
		int res = 0;

		res = sqlite3_step(statement);
		if ( res == SQLITE_DONE )	
		{
			return "";
		} 
		string shortcode = (char*)sqlite3_column_text(statement, 0);
		return shortcode;
	}
	return "";
}

int updateshortcode_actual(string login, string newshortcode)
{
	std::stringstream strm;	
	strm << "update users set shortcode = '" << newshortcode << "' where login = '"  << login << "';";

	string s = strm.str();

	cout << s;

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

		//TO DO: strip login and pass of special characters then query inside.
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
				cout << "Authentication Failed. Please try again" << endl;
			} else {
				int userid = atoi((char*)sqlite3_column_text(statement, 0));
				string insertedon = (char*)sqlite3_column_text(statement, 4);
				string hashedpass = sha256hash(sha256hash(password) + insertedon);	
				string systempass = (char*)sqlite3_column_text(statement, 2);
				int failcnt = atoi((char*)(sqlite3_column_text(statement, 7)));
				string successlogin = ((char*)sqlite3_column_text(statement, 5));
				string faillogin = ((char*)sqlite3_column_text(statement, 6));
				privilege = atoi((char*)(sqlite3_column_text(statement, 3)));

				//************************************************************
				//CHECK IF n secs has passed after lastfaillogin START
				//if yes, reset: resetcounter
				time_t now;
  				time(&now);
				int timedifference = now - atoi((char*)sqlite3_column_text(statement, 6)); // why not faillogin?

				if(timedifference >= LOCKOUTPERIOD) {
					resetcounter(login);
					failcnt = 0;
				}

				//END
				// ************************************************************


				if(failcnt < 3) {
					if(systempass == hashedpass) {	
						authtag = 1;
						currentusername = login;
						currenthashedpassword = systempass;
						currentuserid = userid;
						if(successlogin == "0")
							cout << endl << "No successful logins before.";
						else {
							string successLog = getStringDate(successlogin);
							cout << endl << "Your last successful login was on " << successLog << ".";
						}
						if(faillogin == "0")
							cout << endl << "No unsuccessful logins before." << endl << endl;
						else {
							string failedLog = getStringDate(faillogin);
							cout << endl << "Your last unsuccesful login was on " << failedLog << "." << endl << endl;
						}
						
						char *shortcode = (char*)sqlite3_column_text(statement, 8);
						updateloginhistory(login, true);
						deleteactiveuser();
						insertactiveuser(userid, shortcode, privilege);

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
			}
		}
	}
	return true;
}

string sha256hash(string data)
{
	//string data = "hello";
	byte const* pbData = (byte*) data.data();
    unsigned int nDataLen = data.size();
    byte abDigest[SHA256::DIGESTSIZE];

    SHA256().CalculateDigest(abDigest, pbData, nDataLen);

	//HexEncoder(new FileSink(cout)).Put(abDigest.begin(), abDigest.size());
    //cout << abDigest;
	
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
	
	//cout << encoded << endl;		
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

// For update and insert functionalities

string getinsertedon(string login) {
	sqlite3_stmt *statement;
	string insertedon;
	string q = "select * from users where login = '" + login + "';";
	const char *query = q.c_str();
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int ctotal = sqlite3_column_count(statement);
		int res = 0;
		res = sqlite3_step(statement);
		insertedon = (char*)sqlite3_column_text(statement, 4);
	}
	//cout << endl << insertedon << endl;
	return insertedon;
}

int insertnewuseropenbts(string login, string password)
{
	//Insert dummy row.
	std::stringstream strm;
	strm << "insert into users(login) values('" << login << "');";

	string s = strm.str();
	//cout << s;

	char *str = &s[0];
	//cout << str << endl;
	
	sqlite3_stmt *statement;
	int result;
	//char *query="insert into student(roll,name,cgpa)values(4,'uuu',6.6)";
	char *query = str;
	{
		if(sqlite3_prepare(dbfile,query,-1,&statement,0)==SQLITE_OK)
		{
			int res=sqlite3_step(statement);
			result=res;
			sqlite3_finalize(statement);
		}
		//Update row with real password
		updateuseropenbts(login, password, false);

		return result;
	}
	return 0;
}

int resetcounter(string login)
{
	
	std::stringstream strm;	

	strm << "update users set failcounter = 0 where login = '"  << login << "';";

	string s = strm.str();

	//cout << s;

	char *str = &s[0];
	//cout << str << endl;
	
	sqlite3_stmt *statement;
	int result;
	//char *query="update student set cgpa=3.66 where roll=11";
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


int editprivilege(bool admin, string login)
{
	
	std::stringstream strm;	
	if(admin) {
		strm << "update users set privilege = 1 where login = '"  << login << "';";
	}else {
		strm << "update users set privilege = 0 where login = '"  << login << "';";
	}
	

	string s = strm.str();
	char *str = &s[0];
	//cout << str << endl;
	
	sqlite3_stmt *statement;
	int result;
	//char *query="update student set cgpa=3.66 where roll=11";
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



int pseudoupdate(string login) 
{
	std::stringstream strm;	

	strm << "update users set insertedon = current_timestamp || (strftime('%f', 'now')) || random() where login = '"  << login << "';";

	string s = strm.str();

	//cout << s;

	char *str = &s[0];
	//cout << str << endl;
	
	sqlite3_stmt *statement;
	int result;
	//char *query="update student set cgpa=3.66 where roll=11";
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

int updateuseropenbts(string login, string password, bool tag) 
{
	std::stringstream strm;
	string insertedon = getinsertedon(login);
	string hashedpass = sha256hash(sha256hash(password) + insertedon);
	if(tag) {
		currenthashedpassword = hashedpass;
	}
	//string hashedpass = password;
	strm << "update users set password='" << hashedpass << "' where login='" << login << "';";

	string s = strm.str();

	//cout << s;

	char *str = &s[0];
	//cout << str << endl;
	
	sqlite3_stmt *statement;
	int result;
	//char *query="update student set cgpa=3.66 where roll=11";
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

bool isValid(string input)
{
	int x;

	for (x = 0; x < input.length(); x++) {
		if (input.at(x) > 57 || input.at(x) < 48)
			return false;
	}
	
	return true;
}

int ismodulerestricted(string command) {
	sqlite3_stmt *statement;
	string q = "select * from modules where modulename = '" + command + "';";
	const char *query = q.c_str();
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int res = 0;
		res = sqlite3_step(statement);
		if ( res == SQLITE_DONE )	
		{
			return -1;
		}
		return atoi((char*) sqlite3_column_text(statement, 0));
	}

}

bool userhaspermissions(int userid, int moduleid) {


	std::stringstream strm;	
	
	strm << "select * from userpermissions where moduleid = " << moduleid << " and userid = " << userid << ";";

	string s = strm.str();
	char *str = &s[0];
	sqlite3_stmt *statement;
	int result;
	char *query = str;	
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int res = 0;
		res = sqlite3_step(statement);
		if ( res == SQLITE_DONE )	
		{
			return false;
		}
		return true;
	} else {
		cout << "DD";
	}
	cout << "DDDDDDDDD";
	return true;

}

bool userexists(string login) {
	sqlite3_stmt *statement;
	string q = "select * from users where login = '" + login + "';";
	const char *query = q.c_str();
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int res = 0;
		res = sqlite3_step(statement);
		if ( res == SQLITE_DONE )	
		{
			return false;
		}
		return true;
	}

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
		return (char*)sqlite3_column_text(statement, 0);
	}
}

int deleteactiveuser() {

	char *err = 0;

	const char *query =  "DELETE FROM activeuser;";
	//char *str = &s[0];
	int rc = sqlite3_exec(dbfile, query, callback, 0, &err);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", err);
		sqlite3_free(err);
	}
	return 0;
}

int saveactiveuser(int userid, string shortcode, int privilege) {
	std::stringstream strm;	
	
	strm << "CREATE TABLE activeuser(userid integer,shortcode varchar(10), privilege integer default 0);";

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
		insertactiveuser(userid, shortcode, privilege);
		return result;
	}
	insertactiveuser(userid, shortcode, privilege);
	return 0;
}

int insertactiveuser(int userid, string shortcode, int privilege) {
	std::stringstream strm;	
	
	if(shortcode == " ") {
		strm << "insert into activeuser(userid, privilege) values(" << userid <<  ", " << privilege << ");"; 
	} else {
		strm << "insert into activeuser(userid, shortcode, privilege) values(" << userid << ", '" << shortcode << "', " << privilege << ");"; 
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

int getPrivilege() {
	sqlite3_stmt *statement;
	string q = "select privilege from activeuser;";
	const char *query = q.c_str();
	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int res = 0;
		res = sqlite3_step(statement);
		if ( res == SQLITE_DONE )
		{
			return 0;
		}
		return atoi((char*) sqlite3_column_text(statement, 0));
	}
}
