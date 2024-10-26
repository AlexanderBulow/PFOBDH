﻿// PFOBDH.cpp : Defines the entry point for the application.
//

#include "PFOBDH.h"
#include "GetCommand.h"
#include "SendCommand.h"
#include "Init.h"
#include "SetMode.h"
#include "CheckMode.h"
#include "SetTime.h"
#include "GetTime.h"
#include "changetimecombucket.h"
#include "compareseqinbucket.h"
#include "comparetimeinbucket.h"
#include "editbucket.h"
#include "extractfirstcommandbucket.h"
#include "hhmmss2int.h"
#include "int2hhmmss.h"
#include "removecommandline.h"
#include "timetag.h"
#include "TimeDiff.h"


using namespace std;

int main()
{
	//while (true) {
		GetTime();

		SetTime(22,5,0);
	

		//char command[64] = "something";
		//SendCom(command, 1);

		//cout << "send command";
		//char* receiving = GetCommand(1);
		//cout << receiving << endl;

		
		cout << "start" << endl;
		string newmode = "TargetMode";
		if (SetMode(newmode) == 1) {
			cout << "The mode has been changed to: " << newmode << endl;
		}
		else {
			cout << "New mode is invalid and therefore mode has not been changed ";
		}
		
		cout << "current mode is " << CheckMode() << endl;
		
	//}
	return 0;
}
