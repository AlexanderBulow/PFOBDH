#include "Init.h"

using namespace std;

string mode = "SafeMode";

int TimeElapsed;
int OffsetInTime = 0;
int OldTime;
int nextcommandtime = 1000000;

time_t GetLocalTime = time(nullptr);
string Time = ctime(&GetLocalTime);

int InitialHoursAsInt = stoi(Time.substr(11, 2));
int InitialMinutesAsInt = stoi(Time.substr(14, 2));
int InitialSecondsAsInt = stoi(Time.substr(17, 2));

int bl = 55;
int fl = 100;
int temp = 270;
char housek[64] = { 0 };
char newreceiving[64];
string nextcommand;
char nextcommandch[64] = { 0 };
int runnow;