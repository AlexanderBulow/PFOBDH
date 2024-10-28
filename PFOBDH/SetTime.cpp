#include "SetTime.h"
#include "Init.h"
#include "GetTime.h"
using namespace std;

void SetTime(int curtime) {
	OffsetInTime = curtime - InitialHoursAsInt*3600 - 60* InitialMinutesAsInt - InitialSecondsAsInt;
	GetTime();
}