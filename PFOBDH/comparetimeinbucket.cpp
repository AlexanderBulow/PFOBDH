#include "comparetimeinbucket.h"
#include "hhmmss2int.h"
using namespace std;

int comparetimeinbucket(int commandtime) {
	ifstream bucket("bucket.txt");
	string row, rowstr, currenttime;
	int i = 1;
	while (getline(bucket, row)) {
		stringstream rowstr(row);
		getline(rowstr, currenttime, '-');
		int currenttimeint = hhmmss2int(currenttime);
		if (commandtime < currenttimeint) {
			bucket.close();
			return i;
		}
		else if (commandtime == currenttimeint) { //time is matching one already in the bucket
			bucket.close();
			return 0;
		}
		i++;
	}
	return i;
}