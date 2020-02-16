#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 3000 + 5;

int dp[MAX][MAX];


int main() {
	string str;
	cin >> str;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= str.size(); i++) {
		for (int j = 1; j <= str.size(); j++) {
			if (str[i - 1] == str[str.size() - j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << str.size() - dp[str.size()][str.size()] << endl;

	
	
	return 0;
}