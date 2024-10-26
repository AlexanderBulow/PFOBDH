#include "GetTime.h"
#include "Init.h"
using namespace std;


//The code does not actually need to be this long, although i am unsure how "independent" the time command shall be
int GetTime() {
	time_t GetLocalTime = time(nullptr);
	string Time = ctime(&GetLocalTime);
	int HoursAsInt = stoi(Time.substr(11, 2));
	int MinutesAsInt = stoi(Time.substr(14, 2));
	int SecondsAsInt = stoi(Time.substr(17, 2));
	TimeElapsed = (HoursAsInt * 3600 + MinutesAsInt * 60 + SecondsAsInt) - (3600 * InitialHoursAsInt + 60 * InitialMinutesAsInt + InitialSecondsAsInt) + OffsetInTime;
	int CurrentTime = TimeElapsed + (3600 * InitialHoursAsInt + 60 * InitialMinutesAsInt + InitialSecondsAsInt);
	return CurrentTime;
}
