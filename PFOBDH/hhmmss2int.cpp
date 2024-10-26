#include "hhmmss2int.h"

int hhmmss2int(string timehhmmss) {
	istringstream time(timehhmmss);
	string hourstr, minutestr, secondstr;
	getline(time, hourstr, ':');
	getline(time, minutestr, ':');
	getline(time, secondstr, ':');
	int hour = stoi(hourstr);
	int minute = stoi(minutestr);
	int second = stoi(secondstr);
	int timeint = second + (minute * 60) + (hour * 3600);
	return timeint;
}