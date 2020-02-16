#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX = 1000 + 5;

int dp[MAX][MAX];


int main() {
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	int cnt = dp[n][1];
	for (int i = 2; i <= n; i++) {
		if (cnt < dp[n][i])
			cnt = dp[n][i];
	}
	cout << cnt << endl;
	return 0;
}