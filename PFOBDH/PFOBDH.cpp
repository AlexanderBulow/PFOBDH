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
#include "ValidWrong.h"
#include "timeofextractedcommand.h"
#include "RunCommand.h"


using namespace std;

int main()
{
    int bl = 55;
    int fl = 100;
    int temp = 270;
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
    char newreceiving[64];
    string nextcommand;
    char nextcommandch[64] = { 0 };
    nextcommandch[0] = 'y';
    char* receiving;
    int runnow;
    ofstream fout;
    fout.open("bucket.txt", ios::trunc);
    fout.close();
    while (1) {
        char sendcommandtognd[64] = { 0 };
        string dtime = ("0");
        string argumentstr = ("0");
        valid = 0;
        int argumentt = 300000;
        receiving = GetCommand(1);
        //checking for run now
        if (receiving[0] != 'X') {
            SplitTC(&time, &dtime, sequencef, &targetstr, targetf, &commandstr, commandf, &argumentstr, argumentf, &argumentt, receiving);
        }
        if (dtime == "dddddd") {
            runnow = 1;
        }
        else {
            runnow = 0;
        }
        //checking if the command is valid or not 
        if (receiving[0] != 'X') {
            PF_verify(&time, &dtime, GetTime(), sequencef, targetstr, commandstr, argumentstr, argumentt, &previousseqcount, &currentcount, &valid, &timevalid, &sequencevalid, &targetvalid, &commandvalid, &argumentvalid, receiving);
            if (valid == 1) {
                string add(receiving);
                add = add + " success";
                strcpy(newreceiving, add.c_str());
                SendCom(newreceiving, 2);
            }
            else {
                string add(receiving);
                string wrong = validwrong(timevalid, sequencevalid, targetvalid, commandvalid, argumentvalid);
                add = add + wrong;
                strcpy(newreceiving, add.c_str());
                SendCom(newreceiving, 2);
                add = ("0");
            }
        }
        if (runnow == 0 && valid == 1 && receiving[0] != 'X') {
            if (time<nextcommandtime && nextcommandch[0]!='y') {
                timetag(nextcommandch);
                nextcommandtime = time;
                string nextcommandstring(receiving);
                strcpy(nextcommandch, nextcommandstring.c_str());
            }
            else if (time < nextcommandtime && nextcommandch[0] == 'y') {
                nextcommandtime = time;
                string nextcommandstring(receiving);
                strcpy(nextcommandch, nextcommandstring.c_str());
            }
            else{ 
                timetag(receiving);
            }
        }
        //int bucket = 1;
        //string wholecommand;
        if (receiving[0] == 'X' && GetTime() < nextcommandtime) {
            SendCom(sendcommandtognd, 2);
            SendCom(sendcommandtognd, 3);
        }
        else if(runnow == 1 && valid == 1){
            RunCom(receiving, commandstr, argumentt, argumentstr, commandf, argumentf);
        }
        else {
            //add code to check for next command in bucket and seeing if it is less then current time
            if (GetTime()>=nextcommandtime) {
                SplitTC(&time, &dtime, sequencef, &targetstr, targetf, &commandstr, commandf, &argumentstr, argumentf, &argumentt, nextcommandch);
                RunCom(nextcommandch, commandstr, argumentt, argumentstr, commandf, argumentf);
                nextcommand = extractfirstcommandbucket();
                strcpy(nextcommandch, nextcommand.c_str());
                nextcommandtime = timeofextractedcommand(nextcommand);
            }
            else {
                SendCom(sendcommandtognd, 3);
            }
        }
        //if (GetTime() % 3 == 0) {
            HK(GetTime(), &bl, &fl, &temp, housek);
            SendCom(housek, 4);
            cout << "housekeeping: " << housek << endl;
        //}

	}
	return 0;
}
