#include<iostream>
#include<vector>
using namespace std;

const int Max = 20 + 5;

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

long long int map[Max][Max];
bool d[Max][Max];

int main() {
	long long int n, m, cx, cy;
	cin >> n >> m >> cx >> cy;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			map[i][j] = 0;
			d[i][j] = false;
		}
	d[cx][cy] = true;
	for (int i = 0; i < 8; i++) {
		int tempx = cx + dx[i];
		int tempy = cy + dy[i];
		if (tempx >= 0 && tempx <= n && tempy >= 0 && tempy <= m) {
			d[tempx][tempy] = true;
		}
	}
	map[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (i != 0) {
				if (!d[i][j])
					map[i][j] = map[i][j] + map[i - 1][j];
				else map[i][j] = 0;
			}
			if (j != 0) {
				if (!d[i][j]) {
					map[i][j] = map[i][j] + map[i][j - 1];
				}
				else map[i][j] = 0;
			}
		}
	cout << map[n][m] << endl;
	return 0;
}
