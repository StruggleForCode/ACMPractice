#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define N 105
using namespace std;

struct Note {
	string str;
	int n;
	int num;
};

bool cmp(Note a, Note b) {
	if (a.n < b.n)
		return true;
	if (a.n == b.n && a.num < b.num)
		return true;
	else return false;
}

Note ver[N];

int main() {

	int n, t;
	cin >> n >> t;

	for (int i = 0; i < t; i++) {
		cin >> ver[i].str;
		ver[i].n = 0;
	}

	for (int i = 0; i < t; i++) {
		string s = ver[i].str;
		int ant = 0;
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (s[j] > s[k])
					ant++;
			}
		}
		ver[i].n = ant;
		ver[i].num = i;
	}


	sort(ver, ver + t, cmp);

	for (int i = 0; i < t; i++) {
		cout << ver[i].str  << endl;
	}

	return 0;
}


/*
10 7
AACATGAAGG
GATCAGATTT
AACCTGAAGG
TTTTGGCCAA
TTTGGCCAAA
CCCGGGGGGA
ATCGATGCAT


CCCGGGGGGA 9
AACCTGAAGG
AACATGAAGG 10
GATCAGATTT 11
ATCGATGCAT 17
TTTTGGCCAA 36
TTTGGCCAAA 37

*/