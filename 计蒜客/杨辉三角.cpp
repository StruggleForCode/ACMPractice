#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;

const int Max = 50 + 5;

ll dp[Max][Max];

int main() {
	int n, m;
	cin >> n >> m;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
		//dp[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	cout << dp[n][m] << endl;
	
	return 0;
}