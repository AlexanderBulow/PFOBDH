#include "extractfirstcommandbucket.h"
using namespace std;

string extractfirstcommandbucket() {
	string command, row;
	ifstream bucket("bucket.txt");
	ofstream newbucket("newbucket.txt");
	getline(bucket, command);
	while (getline(bucket, row)) {
		newbucket << row << endl;
	}
	bucket.close();
	newbucket.close();
	remove("bucket.txt");
	rename("newbucket.txt", "bucket.txt");
	return command;
}