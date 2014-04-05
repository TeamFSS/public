#include <sqlite3.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#include "sqlite3.h"
#define DB "openbtsusers.db"

bool isOpenDB = false;
sqlite3 *dbfile;

bool ConnectDB();
void DisconnectDB();


void authenticateuser()
{
	string login;
	string password;
	string userid;
	sqlite3_stmt *statement;	

	char *query = "select * from users";

	if ( sqlite3_prepare(dbfile, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int ctotal = sqlite3_column_count(statement);
		int res = 0;

		int authtag = 0;
		cout << "Please Enter Your Username: ";
		cin >> login;
		cout << "Please Enter Your Password: ";
		cin >> password;

		while ( 1 ) 		
		{
			res = sqlite3_step(statement);
			if ( res == SQLITE_ROW ) 
			{
				userid = (char*)sqlite3_column_text(statement, 0);
				string  s = (char*)sqlite3_column_text(statement, 1);
				if(s == login) {
					string t = (char*)sqlite3_column_text(statement, 2);
					if(t == password) {
						authtag = 1;
						cout << "Authenticated user " << login << " with pass: " << password;
						cout << endl;
						cout << "Userid: " << userid;
						cout << endl;
						break;
					}
				}
			}
			if ( res == SQLITE_DONE )	
			{
				cout << "done " << endl;
				break;
			}					
			
		}
		if(authtag == 0) {
			cout << "Authentication failed." << endl;		
		}
	}

}

int main()
{
	isOpenDB = ConnectDB();

	if ( isOpenDB ) 
		cout << "DB Connected Successfully" << endl;
	else cout << "DB Connection Failed " << endl;

	authenticateuser();

	DisconnectDB();

	
}

bool ConnectDB ()
{
    if ( sqlite3_open(DB, &dbfile) == SQLITE_OK )
    {
        isOpenDB = true;
        return true;
    }         

    return false;
}


void DisconnectDB ()
{
	if ( isOpenDB == true ) 
	{
		sqlite3_close(dbfile);
	}
}
