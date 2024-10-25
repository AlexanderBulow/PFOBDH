#include "SetTime.h"
#include "Init.h"
using namespace std;

void SetTime(int hours, int minutes, int seconds) {
	OffsetInTime = hours * 3600 + minutes * 60 + seconds - InitialHoursAsInt*3600 - 60* InitialMinutesAsInt - InitialSecondsAsInt;
}