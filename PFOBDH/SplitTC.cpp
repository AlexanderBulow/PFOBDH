#include "SplitTC.h"
#include "Init.h"
using namespace std;

void SplitTC(int* time, string* dtime, char* sequencef, string* targetstr, char* targetf, string* commandstr, char* commandf, string* argumentstr, char* argumentf, int* argumentt, char telecommand[64])
{
    char timef[64] = { 0 };
    sequencef[64] = { 0 };
    targetf[64] = { 0 };
    commandf[64] = { 0 };
    argumentf[64] = { 0 };
    int t = 0;
    int s = 0;
    int p = 0;
    int c = 0;
    int a = 0;
    int part = 1; //helps find which part/array of the telecommand should copy the "telecommand" array.
    for (int i = 0; i <= 63; i++) { //goes around 64 times bc thats the size of the telecommand array.
        if (telecommand[i] == '-') //bc we seperate the parts in the telecommand by "-".
        {
            part++; //goes to the next array because the previous one is finished being copied bc of "-".
            continue; //continues the for loop.
        }
        else if (part == 1) {
            if (isdigit(telecommand[i]) || telecommand[i] == 'd') {
                timef[t] = telecommand[i]; //copies from telecommand.
                t++; //goes to the next position in the time array.
            }
            else if (telecommand[i] == ':') {
                continue;
            }
            else {
                part++;
            }

        }
        else if (part == 2) {
            sequencef[s] = telecommand[i]; //copies from telecommand.
            s++; //goes to the next position in the sequence array.
        }
        else if (part == 3) {
            targetf[p] = telecommand[i]; //copies from telecommand.
            p++; //goes to the next position in the target array.
        }
        else if (part == 4 && telecommand[i] != 0) {
            commandf[c] = telecommand[i]; //copies from telecommand.
            c++; //goes to the next position in the command array.
        }
        else if (part == 4 && telecommand[i] == 0) {
            part++;
        }
        else if (part == 5 && telecommand[i] != 0) {
            if (telecommand[i] == ':') {
                continue;
            }
            else {
                argumentf[a] = telecommand[i]; //copies from telecommand.
                a++; //goes to the next position in the argument array.
            }
        }
        else {
            continue;
        }
    }
    sequencef[s] = '\0';
    timef[t] = '\0';
    string timestr(timef);
    if (timestr == "dddddd" || !isdigit(timestr[0])) {
        *dtime = timestr;
    }
    else {
        *time = stoi(timestr);
        int hours = *time / 10000;              // First two digits for hours
        int minutes = (*time / 100) % 100;      // Next two digits for minutes
        int seconds = *time % 100;              // Last two digits for seconds

        // Convert to total seconds
        *time = (hours * 3600) + (minutes * 60) + seconds;
    }
    targetf[p] = '\0';
    commandf[c] = '\0';
    argumentf[a] = '\0';
    *targetstr = string(targetf);
    *commandstr = string(commandf);
    string argumentstri(argumentf);
    if (!argumentstri.empty() && isdigit(argumentf[0])) {
        bool isNumeric = true;
        for (int ar = 0; argumentf[ar] != '\0'; ar++) {
            if (!isdigit(argumentf[ar])) {
                isNumeric = false;
                break;
            }
        }

        if (isNumeric) {
            *argumentt = stoi(argumentstri); // Convert to int if valid
            if (*argumentt >= 59) {
                int hours = *argumentt / 10000;              // First two digits for hours
                int minutes = (*argumentt / 100) % 100;      // Next two digits for minutes
                int seconds = *argumentt % 100;              // Last two digits for seconds

                // Convert to total seconds
                *argumentt = (hours * 3600) + (minutes * 60) + seconds;
            }
        }
        else {
            *argumentstr = argumentstri;
        }
    }
    else {
        *argumentstr = argumentstri;
    }
}