#include "ValidWrong.h"
using namespace std;

string validwrong(int timevalid, int sequencevalid, int targetvalid, int commandvalid, int argumentvalid) {
    if (timevalid == 0) {
        string wrong = " Failed: Time is invalid";
        return wrong;
    }
    else if (sequencevalid == 0) {
        string wrong = " Failed: Sequence is invalid";
        return wrong;
    }
    else if (targetvalid == 0) {
        string wrong = " Failed: Target is invalid";
        return wrong;
    }
    else if (commandvalid == 0) {
        string wrong = " Failed: Command is invalid";
        return wrong;
    }
    else if (argumentvalid == 0){
        string wrong = " Failed: Argument is invalid";
        return wrong;
    }
    else {
        cout << "something wrong with calling validwrong function" << endl;
        return "bad";
    }
}