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
    char newreceiving[64];
    string nextcommand;
    char nextcommandch[64];
    int nextcommandtime = 1000000;



    while (1) {
        char sendcommandtognd[64] = { 0 };
        string dtime = ("0");
        string argumentstr = ("0");
        int argumentt = 300000;
        char* receiving = GetCommand(1);
        int bucket = 1;
        string wholecommand;
        if (receiving == "X"&&GetTime()!=nextcommandtime) {
            SendCom(sendcommandtognd, 1);
            SendCom(sendcommandtognd, 1);
        }
        else {
            if (GetTime() >= nextcommandtime) {
                strcpy(nextcommandch, nextcommand.c_str());
                SplitTC(&time, &dtime, sequencef, &targetstr, targetf, &commandstr, commandf, &argumentstr, argumentf, &argumentt, nextcommandch);
                if (commandstr == "set_time") {
                    SetTime(argumentt);
                    changetimecombucket(TimeDiff());
                    wholecommand = " Time changed ";
                    nextcommandtime = nextcommandtime - TimeDiff();
                }
                else if (commandstr == "chng_mode") {
                    SetMode(argumentstr);
                    SendCom(commandf, 2);
                    char* PLCommand = GetCommand(2);
                    wholecommand = " Mode changed ";
                }
                else if (commandstr == "rmve_data") {
                    removecommandline(argumentt);
                    wholecommand = " Command removed ";
                }
                else if (commandstr == "t_picture") {
                    SendCom(commandf, 2);
                    char* PLCommand = GetCommand(2);
                    wholecommand = PLCommand;
                }
                else {
                    cout << "sum ting wong" << endl;
                }
                string timeofexe = int2hhmmss(GetTime());
                wholecommand = timeofexe + wholecommand;
                strcpy(sendcommandtognd, wholecommand.c_str());
                SendCom(sendcommandtognd, 1);
            }
            else {
                SplitTC(&time, &dtime, sequencef, &targetstr, targetf, &commandstr, commandf, &argumentstr, argumentf, &argumentt, receiving);
                PF_verify(&time, &dtime, GetTime(), sequencef, targetstr, commandstr, argumentstr, argumentt, &previousseqcount, &currentcount, &valid, &timevalid, &sequencevalid, &targetvalid, &commandvalid, &argumentvalid, receiving);
                if (dtime != "dddddd") {
                    string receivingstr(receiving);
                    int receivedcommandtime = timeofextractedcommand(receivingstr);
                    int bucket = comparetimeinbucket(receivedcommandtime) * (nextcommandtime != receivedcommandtime);
                }
                if (valid == 1 && bucket == 1) {
                    string add;
                    strcpy(receiving, add.c_str());
                    add = add + "success";
                    auto first = add.begin();
                    auto last = add.end();
                    // Convert the string to char array
                    copy(first, last, newreceiving);
                    SendCom(newreceiving, 1);

                    if (dtime == "dddddd") {
                        if (commandstr == "set_time") {
                            SetTime(argumentt);
                            changetimecombucket(TimeDiff());
                            wholecommand = " Time changed ";
                            nextcommandtime = nextcommandtime - TimeDiff();
                        }
                        else if (commandstr == "chng_mode") {
                            SetMode(argumentstr);
                            SendCom(commandf, 2);
                            char* PLCommand = GetCommand(2);
                            wholecommand = " Mode changed ";
                        }
                        else if (commandstr == "rmve_data") {
                            removecommandline(argumentt);
                            wholecommand = " Command removed ";
                        }
                        else if (commandstr == "t_picture") {
                            SendCom(commandf, 2);
                            char* PLCommand = GetCommand(2);
                            wholecommand = PLCommand;
                        }
                        else {
                            cout << "sum ting wong" << endl;
                        }
                    }
                    else {
                        string receivingstr(receiving);
                        int receivedcommandtime = timeofextractedcommand(receivingstr);
                        if (nextcommandtime > receivedcommandtime) {
                            strcpy(nextcommandch, nextcommand.c_str());
                            timetag(nextcommandch);
                            nextcommandtime = receivedcommandtime;
                            nextcommand = receivingstr;
                        }
                        else {
                            timetag(receiving);
                        }
                    }
                    string timeofexe = int2hhmmss(GetTime());
                    wholecommand = timeofexe + wholecommand;
                    strcpy(sendcommandtognd, wholecommand.c_str());
                    SendCom(sendcommandtognd, 1);
                }
                else {
                    string add;
                    string wrong = validwrong(timevalid, sequencevalid, targetvalid, commandvalid, argumentvalid, bucket);
                    strcpy(receiving, add.c_str());
                    add = add + wrong;
                    auto first = add.begin();
                    auto last = add.end();
                    // Convert the string to char array
                    copy(first, last, newreceiving);
                    SendCom(newreceiving, 1);
                    SendCom(sendcommandtognd, 1);
                }
            }

        }

       



	}
	return 0;
}
