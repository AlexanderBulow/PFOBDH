#include "Init.h"

using namespace std;

string mode = "SafeMode";

int TimeElapsed;
int OffsetInTime = 0;
int OldTime;

time_t GetLocalTime = time(nullptr);
string Time = ctime(&GetLocalTime);

int InitialHoursAsInt = stoi(Time.substr(11, 2));
int InitialMinutesAsInt = stoi(Time.substr(14, 2));
int InitialSecondsAsInt = stoi(Time.substr(17, 2));