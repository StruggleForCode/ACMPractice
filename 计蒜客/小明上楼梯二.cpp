#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX_N = 50000 + 5;
int num1[MAX_N], num2[MAX_N];
string str[MAX_N];

string add(string s1, string s2) {
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	
	for (int i = s1.size() - 1, j = 0; i >= 0; i--, j++) {
		num1[j] = s1[i] - '0';
	}
	for (int i = s2.size() - 1, j = 0; i >= 0; i--, j++) {
		num2[j] = s2[i] - '0';
	}
	int len = max(s1.size(), s2.size()) + 2;
	for (int i = 0; i < len; i++) {
		num1[i] += num2[i];
		if (num1[i] > 9) {
			num1[i + 1]++;
			num1[i] -= 10;
		}
	}
	
	int i;
	string s = "";
	for (i = len; i >= 0 && num1[i] == 0; i--);
	for (int j = 0; i >= 0; j++, i--) {
		s.push_back(num1[i] + '0');
	}
	return s;
}


int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << n << endl;
		return 0;
	}
	str[1] = "1";
	str[2] = "2";
	for (int i = 3; i <= n; i++) {
		str[i] = add(str[i - 1], str[i - 2]);
	}
	cout << str[n] << endl;
	
	return 0;
}