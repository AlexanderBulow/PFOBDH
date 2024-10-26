// PFOBDH.cpp : Defines the entry point for the application.
//

#include "PFOBDH.h"
#include "GetCommand.h"
#include "SendCommand.h"
#include "SplitTC.h"
#include "clocktoclockr.h"
#include "int2hhmmss.h"
#include "PF_verify.h"
#include "HK.h"

using namespace std;

int main()
{
	while (true) {

		char command[64] = "something";
		SendCom(command, 1);

		cout << "send command";
		//char* receiving = GetCommand(1);
		//cout << receiving << endl;

	}
	return 0;
}
