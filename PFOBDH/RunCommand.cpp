#include "RunCommand.h"
#include "changetimecombucket.h"
#include "GetCommand.h"
#include "SendCommand.h"
#include "removecommandline.h"
#include "SetTime.h"
#include "int2hhmmss.h"
#include "GetTime.h"
#include "SetMode.h"
#include "SplitTC.h"
#include "TimeDiff.h"
using namespace std;

void RunCom(char receivedcom[64], string commandstr, int argumentt, string argumentstr, char commandf[64], char argumentf[64]) {
    string wholecommand;
    if (commandstr == "set_time") {
        SetTime(argumentt);
        changetimecombucket(TimeDiff());
        wholecommand = " Time changed ";
    }
    else if (commandstr == "chng_mode") {
        SetMode(argumentstr);
        SendCom(argumentf, 5);
        char* PLCommand = GetCommand(6);
        wholecommand = " Mode changed ";
    }
    else if (commandstr == "rmve_data") {
        removecommandline(argumentt);
        wholecommand = " Command removed ";
    }
    else if (commandstr == "t_picture") {
        SendCom(commandf, 5);
        char* PLCommand = GetCommand(6);
        wholecommand = PLCommand;
    }
    else {
        cout << "sum ting wong" << endl;
    }
    string timeofexe = int2hhmmss(GetTime());
    wholecommand = timeofexe + wholecommand;
    char sendcommandtognd[64] = {0};
    strcpy(sendcommandtognd, wholecommand.c_str());
    SendCom(sendcommandtognd, 3);
}