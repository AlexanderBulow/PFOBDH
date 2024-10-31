#include "compareseqinbucket.h"
using namespace std;


int compareseqinbucket(int seq) {
	ifstream bucket("bucket.txt");
	string row;
	int i = 1;
	while (getline(bucket, row)) {
		stringstream line(row);
		string element;
		getline(line, element, '-');
		getline(line, element, '-');
		int currentseq = stoi(element);
		if (currentseq == seq) {
			bucket.close();
			cout << currentseq << endl;
			cout << i << endl;
			return i;
		}
		i++;
	}
	bucket.close();
	return 0;
}