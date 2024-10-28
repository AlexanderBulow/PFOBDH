#include "timeofextractedcommand.h"
#include "hhmmss2int.h"
using namespace std;

int timeofextractedcommand(string command) {
	stringstream commandss(command);
	string time;
	getline(commandss, time, '-');
	int timeint = hhmmss2int(time);
	return timeint;
}