#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100 + 5;

int dp[MAX][MAX];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1.size()][s2.size()] << endl;

	if (s1.size() - dp[s1.size()][s2.size()] <= 2)
		cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}