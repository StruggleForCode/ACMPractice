#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

const int MAX = 1000 + 5;

int map[MAX][MAX];
int dp[MAX][MAX];

int judge(int v, int c) {
	if (v >= c)
		return c;
	else if (v <= 0)
		return -1;
	return v;
}

int main() {
	int n, m, x, y, v, c;
	cin >> n >> m >> x >> y >> v >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	}
	map[x][y] += v;
	if (map[x][y] > c)
		map[x][y] = c;

	for (int i = x + 1; i <= n; i++)
		map[i][y] += map[i - 1][y];

	for (int i = x - 1; i >= 1; i--)
		map[i][y] += map[i + 1][y];

	for (int i = y + 1; i <= m; i++)
		map[x][i] += map[x][i - 1];

	for (int i = y - 1; i >= 1; i--)
		map[x][i] += map[x][i + 1];


	for (int i = x - 1; i >= 1; i--) {
		bool istrue = true;
		for (int j = y - 1; j >= 1; j--) {
			map[i][j] += max(map[i + 1][j], map[i][j + 1]);
			map[i][j] = judge(map[i][j], c);
			if (map[i][j] == -1) {
				map[1][1] = -1;
				istrue = false;
				break;
			}
		}
		if (!istrue)
			break;
	}

	for (int i = x - 1; i >= 1; i--) {
		bool istrue = true;
		for (int j = y + 1; j <= m; j++) {
			map[i][j] += max(map[i + 1][j], map[i][j - 1]);
			map[i][j] = judge(map[i][j], c);
			if (map[i][j] == -1) {
				map[1][m] = -1;
				istrue = false;
				break;
			}
		}
		if (!istrue)
			break;
	}

	for (int i = x + 1; i <= n; i++) {
		bool istrue = true;
		for (int j = y - 1; j >= 1; j--) {
			map[i][j] += max(map[i - 1][j], map[i][j + 1]);
			map[i][j] = judge(map[i][j], c);
			if (map[i][j] == -1) {
				map[n][1] = -1;
				istrue = false;
				break;
			}
			
		}
		if (!istrue)
			break;
	}

	for (int i = x + 1; i <= n; i++) {
		bool istrue = true;
		for (int j = y + 1; j <= m; j++) {
			map[i][j] += max(map[i - 1][j], map[i][j - 1]);
			map[i][j] = judge(map[i][j], c);
			if (map[i][j] == -1) {
				map[n][m] = -1;
				istrue = false;
				break;
			}
		}
		if (!istrue)
			break;
	}

	int _max = max(map[1][1], max(map[1][m], max(map[n][1], map[n][m])));
	//cout << _max << endl;

	int m1 = max(map[1][1], map[1][m]);
	int m2 = max(map[n][1], map[n][m]);
	cout << max(m1, m2) << endl;

	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			cout << map[i][j] << "    ";
		cout << endl;
	}*/


	
	return 0;
}