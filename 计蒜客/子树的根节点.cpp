#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1000 + 5;

struct edge {
	int v, next;
};

edge p[MAX_N];
int head[MAX_N], eid;
int cnt[MAX_N];
bool flag[MAX_N];

void init() {
	memset(head, -1, sizeof(head));
	memset(flag, false, sizeof(flag));
	eid = 0;
}

void addedge(int u, int v) {
	p[eid].v = v;
	p[eid].next = head[u];
	head[u] = eid++;
}



void dfs(int u) {
	flag[u] = true;
	bool isleaf = true;
	for (int i = head[u]; i != -1; i = p[i].next) {
		if (!flag[p[i].v]) {
			dfs(p[i].v);
			isleaf = false;
			cnt[u] += cnt[p[i].v];
		}
	}
	if (isleaf) {
		cnt[u] = 1;
	}
	else cnt[u] += 1;
}


int main() {
	int n;
	cin >> n;
	init();
	int a = n;
	n--;
	while (n--) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
	}

	dfs(1);
	for (int i = 1; i <= a; i++)
		cout << cnt[i] << (i == a ? '\n': ' ');
	return 0;
}