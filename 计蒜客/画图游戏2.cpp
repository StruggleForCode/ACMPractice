#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int  N = 20;
pair<int, int> a[N];
int G[N][N];


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	while (true) {
		sort(a, a + n);
		if (a[n - 1].first == 0) break;
		int x = a[n - 1].second;
		for (int i = n - 2; i >= 0 && a[n - 1].first > 0 && a[i].first > 0; i--) {
			int y = a[i].second;
			if (G[x][y])continue;
			G[x][y] = G[y][x] = 1;
			a[n - 1].first--;
			a[i].first--;
		}
		if (a[n - 1].first > 0) {
			puts("None");
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%c", G[i][j], j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;

}