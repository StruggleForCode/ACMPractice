#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 10000 + 5;
const int MAX_M = 50000 + 5;

struct edge {
	int v, next;
};

edge p[MAX_M << 1];
int head[MAX_N];
int flag[MAX_M << 1];
int eid;

void init() {
	memset(head, -1, sizeof(head));
	eid = 0;
	memset(flag, false, sizeof(flag));
}

void addedge(int u, int v) {
	p[eid].v = v;
	p[eid].next = head[u];
	head[u] = eid++;
}

void dfs(int u) {
	for (int i = head[u]; i != -1; i = p[i].next) {
		if (!flag[i]) {
			flag[i] = true;
			dfs(p[i].v);
		}
	}
	cout << u << endl;
}


int main() {
	int n, m;
	cin >> n >> m;
	init();
	while (m--) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}

	dfs(1);

	return 0;
}