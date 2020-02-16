#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 10000;

int num1[MAX], num2[MAX], num3[MAX];

string mulit(string s1, string s2) {
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
	string s1, s2;
	cin >> s1 >> s2;
	cout << mulit(s1, s2) << endl;
	return 0;
}