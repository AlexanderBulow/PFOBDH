#include "changetimecombucket.h"
#include "hhmmss2int.h"

void changetimecombucket(int time) {
	string row, commandtime;
	ifstream bucket("bucket.txt");
	ofstream newbucket("newbucket.txt");
	while (getline(bucket, row)) {
		stringstream rowstr(row);
		getline(rowstr, commandtime, '-');
		int commandtimeint = hhmmss2int(commandtime);
		int newcommandtime = commandtimeint - time;
		string newtime = int2hhmmss(newcommandtime);
		row.replace(0, 8, newtime);
		newbucket << row << endl;
	}
	bucket.close();
	newbucket.close();
	remove("bucket.txt");
	rename("newbucket.txt", "bucket.txt");
}
