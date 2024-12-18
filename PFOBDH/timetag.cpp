#include "timetag.h"
#include "hhmmss2int.h"
#include "comparetimeinbucket.h"
using namespace std;

int timetag(char kuk[64]) {
	istringstream commandss(kuk);
	string commandtime;
	getline(commandss, commandtime, '-');
	int commandtimeint = hhmmss2int(commandtime);
	int placement = comparetimeinbucket(commandtimeint);
	if (placement == 0) {
		return 0; //time is matching one already in the bucket
	}
	ifstream bucket("bucket.txt");
	ofstream newbucket("newbucket.txt");
	string row;
	int i = 1;
	while (getline(bucket, row)) {
		if (i == placement) {
			newbucket << kuk << endl;
		}
		newbucket << row << endl;
		i++;
	}
	if (i == placement) {
		newbucket << kuk << endl;
	}
	bucket.close();
	newbucket.close();
	remove("bucket.txt");
	rename("newbucket.txt", "bucket.txt");
	return 1;
}