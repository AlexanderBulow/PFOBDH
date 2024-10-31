#include "HK.h"
#include "int2hhmmss.h"
using namespace std;

void HK(int clock, int* bl, int* fl, int* temp, char* housek) {
    housek[64] = { 0 };
    int randomnumber = rand() % 2;
    if (randomnumber == 0) {
        *bl = *bl - (rand() % 4);
        *fl = *fl - (rand() % 2);
        *temp = *temp + (rand() % 2);
    }
    else {
        *bl = *bl + (rand() % 4);
        *temp = *temp - (rand() % 2);
    }

    string clockstrcomplete = int2hhmmss(clock);
    string blstr = to_string(*bl);
    string flstr = to_string(*fl);
    string tempstr = to_string(*temp);
    string abc = clockstrcomplete + '-' + blstr + '-' + flstr + '-' + tempstr;
    strcpy(housek, abc.c_str());
}