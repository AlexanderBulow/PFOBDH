// PFOBDH.cpp : Defines the entry point for the application.
//

#include "PFOBDH.h"
#include "GetCommand.h"
#include "SendCommand.h"
#include "Init.h"
#include "SetMode.h"
#include "CheckMode.h"
#include "SetTime.h"
#include "GetTime.h"

using namespace std;

int main()
{
	//while (true) {
		int Time1 = GetTime();
		int hours1 = Time1 / 3600;            // Calculate hours
		Time1 %= 3600;                   // Remaining seconds after extracting hours
		int minutes1 = Time1 / 60;            // Calculate minutes
		int seconds1 = Time1 % 60;
		cout << hours1 << minutes1 << seconds1 << endl;
		SetTime(22,5,0);
		sleep(4);
		int Time2 = GetTime();
		int hours2 = Time2 / 3600;            // Calculate hours
		Time2 %= 3600;                   // Remaining seconds after extracting hours
		int minutes2 = Time2 / 60;            // Calculate minutes
		int seconds2 = Time2 % 60;
		cout << hours2 << minutes2 << seconds2;
		//char command[64] = "something";
		//SendCom(command, 1);

		//cout << "send command";
		//char* receiving = GetCommand(1);
		//cout << receiving << endl;

		/*
		cout << "start";
		string newmode = "TargetMode";
		if (SetMode(newmode) == 1) {
			cout << "The mode has been changed to: " << newmode << endl;
		}
		else {
			cout << "New mode is invalid and therefore mode has not been changed ";
		}*/
		
		//cout << "current mode is " << CheckMode() << endl;
		
	//}
	return 0;
}
