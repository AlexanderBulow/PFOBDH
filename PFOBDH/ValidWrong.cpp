#include "ValidWrong.h"
using namespace std;

string validwrong(int timevalid, int sequencevalid, int targetvalid, int commandvalid, int argumentvalid) {

    string wrong = "0";
    if (timevalid == 0) {
        wrong = " Failed: Time is invalid";
        return wrong;
    }
    else if (sequencevalid == 0) {
        wrong = " Failed: Sequence is invalid";
        return wrong;
    }
    else if (targetvalid == 0) {
        wrong = " Failed: Target is invalid";
        return wrong;
    }
    else if (commandvalid == 0) {
        wrong = " Failed: Command is invalid";
        return wrong;
    }
    else if (argumentvalid == 0) {
        wrong = " Failed: Argument is invalid";
        return wrong;
    }
    else {
        wrong = " Something is very wrong ith code";
        return wrong;

    }
}