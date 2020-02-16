#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX = 50 + 5;

int map[MAX][MAX];
int dp[MAX][MAX][MAX];

/*
dp[i][j][k][l]表示一个点在（i,j）,另一条线路的点是（k，l） ！因为走过的步数相同l=i+j-k;
*/


int main() {
	int n, m;
	cin >> n >> m;
	memset(map, 0, sizeof(map));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= n && k < i + j; k++) {
				if (k == i)
					continue;
				dp[i][j][k] = max(dp[i][j - 1][k], max(dp[i - 1][j][k - 1], max(dp[i][j - 1][k - 1], dp[i - 1][j][k]))) + map[i][j] + map[k][i + j - k];
			}
		}
	}

	cout << dp[n][m][n - 1] << endl;
	
	return 0;
}