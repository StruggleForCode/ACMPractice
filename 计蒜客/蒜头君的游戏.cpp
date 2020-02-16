#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX = 30 + 5;

ll dp[MAX][MAX];

int main() {
	int n, m;
	cin >> n >> m;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i - 1][(j + 1) % n] + dp[i - 1][(j + n - 1) % n];
		}
	}
	cout << dp[m][0] << endl;
	return 0;
}
