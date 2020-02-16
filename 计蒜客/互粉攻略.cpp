#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1000 + 5;
int G[MAX_N][MAX_N];

int attention[MAX_N], follow[MAX_N];


int main() {
	int n, m;
	cin >> n >> m;
	memset(attention, 0, sizeof(attention));
	memset(follow, 0, sizeof(follow));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = 0;
		}
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		G[a][b] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (G[i][j]) {
				attention[i]++;
				follow[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << follow[i] - attention[i] << endl;
	}
	return 0;
}