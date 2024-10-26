#include "int2hhmmss.h"
using namespace std;

string int2hhmmss(int clock) {
	int hourss = clock / 3600;
	int minutess = (clock % 3600) / 60;
	int secondss = clock % 60;
	int newtime = (hourss * 10000) + (minutess * 100) + secondss;
	string clockstr = to_string(newtime);
	string zeroesstr = string(6 - clockstr.length(), '0') + clockstr;
	string clockstrcomplete = zeroesstr.substr(0, 2) + ":" + zeroesstr.substr(2, 2) + ":" + zeroesstr.substr(4, 2);
	return clockstrcomplete;
}