#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int MAX_N = 1000 + 5;

struct edge {
	int v, next;
}E[MAX_N * MAX_N];

int p[MAX_N], eid;
bool flag[MAX_N];
int n, m;

void init() {
	memset(flag, false, sizeof(flag));
	memset(p, -1, sizeof(p));
	eid = 0;
}

void insert(int u, int v) {
	E[eid].v = v;
	E[eid].next = p[u];
	p[u] = eid++;
}


void dfs(int u) {
	flag[u] = true;
	for (int i = p[u]; i != -1; i = E[i].next) {
		if (!flag[E[i].v])
			dfs(E[i].v);
	}
	return;
}

int main() {
	cin >> n >> m;
	init();
	while (m--) {
		int u, v;
		cin >> u >> v;
		insert(u, v);
		insert(v, u);
	}
	dfs(1);
	/*cout << endl;
	for (int u = 1; u <= 5; ++u) {
		cout << u << "    ";
		for (int i = p[u]; i + 1; i = E[i].next) {
			cout << E[i].v << " ";
		}
		cout << endl;
	}*/
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			cnt++;
			dfs(i);
			//cout << i << "  ";
		}
	}
	//cout << endl;
	cout << cnt << endl;
	
	return 0;
}