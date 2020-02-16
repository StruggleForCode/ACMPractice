#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;

const int MAX_N = 100000;
const int MAX_M = 1000000 + 5;
int father[MAX_N];

void init() {
	for (int i = 0; i < MAX_N; i++) {
		father[i] = i;
	}
}

int find(int u) {
	return u == father[u] ? u : father[u] = find(father[u]);
}

void merge(int u, int v) {
	father[find(u)] = find(v);
}

int n, m;

int main() {
	int num = 1;
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0)
			break;
		init();
		char c;
		int u, v;
		while (m--) {
			scanf(" %c %d", &c, &u);
			if (c == 'M') {
				scanf("%d", &v);
				if (father[u] == -1 || father[v] == -1)
					continue;
				merge(u, v);
			}
			else if (c == 'S') {
				father[u] = -1;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			//cout << father[i] << " ";
			if (father[i] == -1)
				continue;
			if (father[father[i]] == -1)
				cnt++;
			if (father[i] == i) {
				cnt++;
			}
		}
		printf("Case #%d: %d\n", num, cnt);
		num++;
	}
	return 0;
}