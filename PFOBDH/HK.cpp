#include "HK.h"
#include "int2hhmmss.h"
using namespace std;

void HK(int clock, int* bl, int* fl, int* temp, char* housek) {
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

    for (int cl = 0; cl < 8; cl++) {
        housek[cl] = clockstrcomplete[cl];
    }

    string blstr = to_string(*bl);
    string flstr = to_string(*fl);
    string tempstr = to_string(*temp);

    housek[8] = '-';
    housek[9] = blstr[0];
    housek[10] = blstr[1];
    housek[11] = '-';
    housek[12] = flstr[0];
    housek[13] = flstr[1];
    housek[14] = '-';
    housek[15] = tempstr[0];
    housek[16] = tempstr[1];

    housek[17] = '\0'; // Null-terminate the string
}