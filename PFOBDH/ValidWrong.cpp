#include "ValidWrong.h"
using namespace std;

string validwrong(int timevalid, int sequencevalid, int targetvalid, int commandvalid, int argumentvalid, int bucket) {
    if (timevalid == 0) {
        string wrong = "Failed: Time is invalid";
        return wrong;
    }
    else if (sequencevalid == 0) {
        string wrong = "Failed: Sequence is invalid";
        return wrong;
    }
    else if (targetvalid == 0) {
        string wrong = "Failed: Target is invalid";
        return wrong;
    }
    else if (commandvalid == 0) {
        string wrong = "Failed: Command is invalid";
        return wrong;
    }
    else if (bucket == 0) {
        string wrong = "Failed: Time-tag already in use";
        return wrong;
    }
    else {
        string wrong = "Failed: Argument is invalid";
        return wrong;
    }
}