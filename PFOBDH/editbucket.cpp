#include "editbucket.h"
#include "compareseqinbucket.h"
#include "removecommandline"


string editbucket(char command[32], char argch[32]) { //command is the command (remove_command) the only, argch is the argument (all for wipe'ing the txtfile or sequencenumber of the decired command to remove)
	string arg(argch);
	string com(command);
	string ack;
	if (com == "remove_command") {
		if (arg == "all") {
			ofstream bucket("bucket.txt");
			bucket.close();
			ack="removed all commands from commandbucket"
		}
		else if (compareseqinbucket(stoi(arg)) != 0) {
			removecommandline(compareseqinbucket(stoi(arg)));
			ack = "removed 1 line in commandbucket"
		}
		else {
			ack = "invalid argument";
		}
	}
	else {
		ack = "invalid command sent to editbucket";
	}
	return ack;
}
