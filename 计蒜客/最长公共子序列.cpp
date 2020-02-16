#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 1000 + 5;

int dp[MAX][MAX];

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i <= s1.size(); i++) {
		for (int j = 0; j <= s2.size(); j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
		}
	}

	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	
	cout << dp[s1.size()][s2.size()] << endl;

	return 0;
}