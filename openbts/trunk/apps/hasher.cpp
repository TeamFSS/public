#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#ifdef HAVE_LIBREADLINE
#  include <readline/readline.h>
#  include <readline/history.h>
#endif


#define DEFAULT_CMD_PATH "/var/run/command"
#define DEFAULT_RSP_PATH "./response"

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

using namespace std;
using namespace CryptoPP;

#include "sqlite3.h"
#define DB "openbtsusers.db"

string sha256hash(string);

int main(int argc, char *argv[])
{
	string hashed = sha256hash('12345');
	cout << hashed;
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

