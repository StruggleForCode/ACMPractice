#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX = 1000000 + 5;


struct edge {
	int to, next;
};

int head[MAX], eid;

void init() {
	memset(head, -1, sizeof(head));
	eid = 0;
}

int num1[MAX], num2[MAX], num3[MAX];

string mulit(string s1, string s2) {
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(num3, 0, sizeof(num3));
	for (int i = s1.size() - 1, j = 0; i >= 0; i--, j++) {
		num1[j] = s1[i] - '0';
	}
	for (int i = s2.size() - 1, j = 0; i >= 0; i--, j++) {
		num2[j] = s2[i] - '0';
	}
	int len = max(s1.size(), s2.size()) + 10;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			num3[i + j] += num1[i] * num2[j];
		}
	}
	for (int i = 0; i < len; i++) {
		if (num3[i] > 9) {
			num3[i + 1] += num3[i] / 10;
			num3[i] %= 10;
		}
	}
	string s = "";
	int i;
	for (i = len; i >= 0 && num3[i] == 0; i--);
	for (; i >= 0; i--) {
		s.push_back(num3[i] + '0');
	}
	return s;
}


int main() {
	string s;
	cin >> s;
	string s1 = "1";
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp.push_back(s[i]);
		}
		else {
			if (temp == "0") {
				cout << 0 << endl;
				return 0;
			}
			s1 = mulit(temp, s1);

			temp = "";
		}
	}
	if (temp == "0") {
		cout << 0 << endl;
		return 0;
	}
	s1 = mulit(temp, s1);
	cout << s1 << endl;
	return 0;
}