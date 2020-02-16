#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 105;
int map[MAX_N][MAX_N];

int main() {
	int n, m;
	int a;
	cin >> n >> m;
	memset(map, 0, sizeof(map));
	while (m--) {
		int x, y;
		cin >> a >> x >> y;
		map[x][y] = 1;
		if (a == 1) {
			map[y][x] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << map[i][n - 1] << endl;
	}
	return 0;
}