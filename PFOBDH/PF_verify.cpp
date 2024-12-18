#include "clocktoclockr.h"
#include "PF_verify.h"
#include "SendCommand.h"
#include "GetTime.h"
#include "Init.h"
using namespace std;

void PF_verify(int* time, string* dtime, int clock, char sequencef[64], string targetstr, string commandstr, string argumentstr, int argumentt, int* previousseqcount, int* currentcount, int* valid, int* timevalid, int* sequencevalid, int* targetvalid, int* commandvalid, int* argumentvalid, char telecommand[64])
{
    int tr = 1;
    int fa = 0;
    *timevalid = 0;
    *sequencevalid = 0;
    *targetvalid = 0;
    *commandvalid = 0;
    *argumentvalid = 0;
    //everything in the if statement below is for validating the timestamp in the telecommand
    //checks that the time array has something other than zeroes
    //checks if time has already occured

    if (*dtime == "dddddd") {
        *timevalid = tr;
    }
    else if (*time >= (GetTime())+10) {
        *timevalid = tr;
        //this means its timetagged
    }
    else {
        //time-tagged is not valid
        *timevalid = fa;
    }

    //checking that sequence counter is valid
    int sequencenumber = 0;
    for (int i = 0; sequencef[i] != '\0'; i++) {
        if (isdigit(sequencef[i])) {
            sequencenumber = sequencenumber * 10 + (sequencef[i] - '0');
            if (sequencenumber - 1 == *previousseqcount) {
                *sequencevalid = tr;
                *currentcount = *previousseqcount + 1;
            }
            else {
                *sequencevalid = fa;
            }
        }
        else {
            *sequencevalid = fa;
        }
    }
    //checking that target is valid = ("PF" or "PL")
    if (targetstr == "PF" || targetstr == "PL") {
        *targetvalid = tr;
    }
    else {
        *targetvalid = fa;
    }
    //checking that command is valid
    if (commandstr == "set_time" || commandstr == "chng_mode" || commandstr == "crnt_mode" || commandstr == "rmve_data" || commandstr == "t_picture") {
        *commandvalid = tr;
    }
    else {
        *commandvalid = fa;
    }
    //checking that argument is valid
    if (argumentstr == "safemode" || argumentstr == "targetmode" || argumentstr == "all" || (argumentt == 300000 && argumentstr.empty()) || argumentt < 300000) {
        *argumentvalid = tr;
    }
    else {
        *argumentvalid = fa;
    }
    if (*timevalid == 1 && *targetvalid == 1 && *commandvalid == 1 && *argumentvalid == 1 && *sequencevalid == 1) {
        *previousseqcount = *currentcount;
        //send to grn: "telcommand" is not valid.
        *valid = 1;
    }
    else {
        //send to grn: "telecommand is valid.
        *valid = 0;
        *currentcount = *currentcount - 1;
    }
}