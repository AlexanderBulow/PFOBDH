#include "clocktoclockr.h"
#include "PF_verify.h"
#include "SendCommand.h"
using namespace std;

void PF_verify(int* time, string* dtime, int clock, char sequence[64], string targetstr, string commandstr, string argumentstr, int argumentt, int* previousseqcount, int* currentcount, int* valid, char telecommand[64])
{
    int tr = 1;
    int fa = 0;
    int timevalid = 0;
    int sequencevalid = 0;
    int targetvalid = 0;
    int commandvalid = 0;
    int argumentvalid = 0;
    //everything in the if statement below is for validating the timestamp in the telecommand
    //checks that the time array has something other than zeroes
    //checks if time has already occured
    clocktoclockr(&clock);
    if (*dtime == "dddddd") {
        timevalid = tr;
    }
    else if (*time >= (clock)+10) {
        timevalid = tr;
        //this means its timetagged
    }
    else {
        //time-tagged is not valid
        timevalid = fa;
    }

    //checking that sequence counter is valid
    int sequencenumber = 0;
    for (int i = 0; sequence[i] != '\0'; i++) {
        if (isdigit(sequence[i])) {
            sequencenumber = sequencenumber * 10 + (sequence[i] - '0');
            if (sequencenumber - 1 == *previousseqcount) {
                sequencevalid = tr;
                *currentcount = *previousseqcount + 1;
            }
            else {
                sequencevalid = fa;
            }
        }
        else {
            sequencevalid = fa;
        }
    }
    //checking that target is valid = ("PF" or "PL")
    if (targetstr == "PF" || targetstr == "PL") {
        targetvalid = tr;
    }
    else {
        targetvalid = fa;
    }
    //checking that command is valid
    if (commandstr == "set_time" || commandstr == "chng_mode" || commandstr == "crnt_mode" || commandstr == "rmve_data" || commandstr == "t_picture") {
        commandvalid = tr;
    }
    else {
        commandvalid = fa;
    }
    //checking that argument is valid
    if (argumentstr == "safemode" || argumentstr == "targetmode" || argumentstr == "all" || (argumentt == 2000 && argumentstr.empty()) || argumentt < 2000) {
        argumentvalid = tr;
    }
    else {
        argumentvalid = fa;
    }
    if (previousseqcount != currentcount && (timevalid != 1 || targetvalid != 1 || commandvalid != 1 || argumentvalid != 1 || sequencevalid != 1)) {
        *currentcount = *currentcount - 1;
        //send to grn: "telcommand" is not valid.
        *valid = 0;
    }
    else {
        *previousseqcount = *currentcount;
        //send to grn: "telecommand is valid.
        *valid = 1;
    }
}