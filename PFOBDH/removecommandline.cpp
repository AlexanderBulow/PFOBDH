#include "removecommandline.h"
using namespace std;

void removecommandline(int removeline) {
	ifstream bucket("bucket.txt");
	ofstream newbucket("newbucket.txt");
	string row;
	int i = 0;
	while (getline(bucket, row)) {
		if (i != removeline) {
			newbucket << row << endl;
		}
		i++;
	}
	bucket.close();
	newbucket.close();
	remove("bucket.txt");
	rename("newbucket.txt", "bucket.txt");
}