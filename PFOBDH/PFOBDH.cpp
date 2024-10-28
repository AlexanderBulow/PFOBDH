// PFOBDH.cpp : Defines the entry point for the application.
//

#include "PFOBDH.h"
#include "GetCommand.h"
#include "SendCommand.h"
#include "SplitTC.h"
#include "clocktoclockr.h"
#include "int2hhmmss.h"
#include "PF_verify.h"
#include "HK.h"
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
    int bl = 55;
    int fl = 50;
    int temp = 15;
    char housek[64] = { 0 };
    int time = 0;
    char sequencef[64] = { 0 };
    char targetf[64] = { 0 };
    char commandf[64] = { 0 };
    char argumentf[64] = { 0 };
    int previousseqcount = 0;
    int currentcount = 0;
    int valid = 0;
    string targetstr = ("0");
    string commandstr = ("0");
    int timevalid = 0;
    int sequencevalid = 0;
    int targetvalid = 0;
    int commandvalid = 0;
    int argumentvalid = 0;



	while (1) {
        string dtime = ("0");
        string argumentstr = ("0");
        int argumentt = 2000;

		char* receiving = GetCommand(1);
		if (receiving == "X") {

		}
		else {
			SplitTC(&time, &dtime, sequencef, &targetstr, targetf, &commandstr, commandf, &argumentstr, argumentf, &argumentt, receiving);
            PF_verify(&time, &dtime, GetTime(), sequencef, targetstr, commandstr, argumentstr, argumentt, &previousseqcount, &currentcount, &valid, &timevalid, &sequencevalid, &targetvalid, &commandvalid, &argumentvalid, receiving);
            if (valid == 1) {
                string add;
                strcpy(receiving, add.c_str());
                add = add + "success";
                auto first = add.begin();
                auto last = add.end();
                // Convert the string to char array
                copy(first, last, receiving);
                SendCom(receiving, 1);
            }
            else {
                string add;
                strcpy(receiving, add.c_str());
                add = add + "fail";
                auto first = add.begin();
                auto last = add.end();
                // Convert the string to char array
                copy(first, last, receiving);
                SendCom(receiving, 1);
            }
		}
        

	}
	return 0;
}
