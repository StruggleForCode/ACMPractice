#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
const int MAX = 100 + 5;
const int inf = 0x3f3f3f;

struct edge {
	int to, cost, next;
};

struct node {
	int v, w;
	node(int _v, int _w) :v(_v), w(_w) {};
};

edge e[MAX << 1];
int head[MAX];
int dis[MAX];
int vis[MAX];
int times[MAX];
int eid;
int n;

void init() {
	for (int i = 0; i < MAX; i++) {
		head[i] = -1;
	}
	eid = 0;
}

void insert(int u, int v, int w) {
	e[eid].to = v;
	e[eid].cost = w;
	e[eid].next = head[u];
	head[u] = eid++;
}

bool SPFA(int u) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	memset(times, 0, sizeof(times));
	queue<node> que;
	que.push(node(u, 100));
	vis[u] = true;
	while (!que.empty()) {
		node now = que.front();
		que.pop();
		vis[now.v] = false;
		for (int i = head[now.v]; ~i; i = e[i].next) {
			int v = e[i].to;
			int w = e[i].cost;
			if (dis[v] < dis[now.w] + w) {
				dis[v] = dis[now.w] + w;
				if (times[v] <= n && !vis[v]) {
					que.push(node(v, dis[v]));
					times[v]++;
				}
				if (times[v] > n) {
					dis[v] = inf;
				}
			}
		}
	}
	return true;
}


int main() {
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b;
		while (b--) {
			cin >> c;
			insert(i, c, a);
		}
	}
	if (SPFA(1) && dis[n] > 0 && dis[n] < inf) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
