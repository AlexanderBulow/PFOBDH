#include "editbucket.h"
#include "compareseqinbucket.h"
#include "removecommandline.h"
#include "Init.h"
using namespace std;

string editbucket(char command[64], char argch[64]) { //command is the command (remove_command) the only, argch is the argument (all for wipe'ing the txtfile or sequencenumber of the decired command to remove)
	string arg(argch);
	string com(command);
	string ack;
	if (com == "rmve_data") {
		if (arg == "all") {
			ofstream bucket("bucket.txt");
			bucket.close();
			ack = "removed all commands from commandbucket";
			nextcommandch[0] = 'y';
			nextcommandtime = 1000000;
		}
		else if (compareseqinbucket(stoi(arg)) != 0) {
			removecommandline(compareseqinbucket(stoi(arg)));
			ack = "removed 1 line in commandbucket";
		}
		else {
			cout << compareseqinbucket(stoi(arg)) << endl;
			ack = "invalid argument";
		}
	}
	else {
		ack = "invalid command sent to editbucket";
	}
	return ack;
}
