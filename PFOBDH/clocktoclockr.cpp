#include "clocktoclockr.h"
using namespace std;

void clocktoclockr(int* clock) {
    // Calculate hours, minutes, and seconds
    int hourss = *clock / 3600;
    int minutess = (*clock % 3600) / 60;
    int secondss = *clock % 60;

    // Construct the "clock" integer in HHMMSS format
    *clock = (hourss * 10000) + (minutess * 100) + secondss;
}