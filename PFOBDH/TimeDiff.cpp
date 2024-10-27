#include "TimeDiff.h"
#include "Init.h"
#include "GetTime.h"

using namespace std;

int TimeDiff() {
	OldTime = TimeElapsed - OffsetInTime + (3600 * InitialHoursAsInt + 60 * InitialMinutesAsInt + InitialSecondsAsInt);
	return OldTime - GetTime();
}