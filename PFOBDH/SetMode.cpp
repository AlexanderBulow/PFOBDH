#include "Init.h"
#include "SetMode.h"

using namespace std;

int SetMode(string changemode) {
	//changes mode if the mode is allowed and returns a 1 else it returns 0 without doing anything
	if (changemode == "TargetMode" || changemode == "SafeMode") {
		mode = changemode;
		return 1;
	}
	else {
		return 0;
	}
}


