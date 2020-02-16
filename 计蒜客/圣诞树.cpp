#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

const int MAX = 500000 + 5;
const int inf = 0x3f3f3f;

struct edge {
	int to, cost, next;
};

struct node {
	int dis; int to;
	node(int _dis, int _to) : dis(_dis), to(_to) {}
	bool operator < (const node a) const {
		return dis > a.dis;
	}
};

edge e[MAX];
int head[MAX];
int eid;
int dis[MAX];
int w[MAX];
int vis[MAX];

void init() {
	for (int i = 0; i < MAX; i++)
		head[i] = -1;
	eid = 0;
}

void insert(int u, int v, int w) {
	e[eid].to = v;
	e[eid].cost = w;
	e[eid].next = head[u];
	head[u] = eid++;
}


void Dijkstra(int u) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(dis));
	priority_queue<node> que;
	que.push(node(0, u));
	dis[u] = 0;
	while (!que.empty()) {
		node now = que.top();
		que.pop();
		if (vis[now.to])
			continue;
		vis[now.to] = true;
		for (int i = head[now.to]; ~i; i = e[i].next) {
			int v = e[i].to;
			int w = e[i].cost;
			if (!vis[v] && dis[v] > dis[now.to] + w) {
				dis[v] = dis[now.to] + w;
				que.push(node(dis[v], v));
			}
		}
	}
}


int main() {
	init();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		insert(u, v, w);
		insert(v, u, w);
	}

	Dijkstra(1);
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dis[i] >= inf) {
			cout << "No Answer" << endl;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt += dis[i] * w[i];
	}
	cout << cnt << endl;
	
	return 0;
}