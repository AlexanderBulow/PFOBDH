#include "timeofextractedcommand.h"
#include "hhmmss2int.h"
using namespace std;

int timeofextractedcommand(string command) {
	string time;
	getline(command, time, '-');
	int timeint = hhmmss2int(time);
	return timeint;
}