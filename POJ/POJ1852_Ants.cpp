
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
const int inf = 0x3f3f3f;
const int MAX = 10000 + 5;

struct edge {
	int to, cost, next;
}e[MAX << 1];

struct node {
	int v, w;
	node(int _v, int _w) :v(_v), w(_w) {};
	bool operator < (const node a) {
		return w > a.w;
	}
};

int n, m;
int head[MAX];
int eid;
int dis[MAX];
bool vis[MAX];
int times[MAX];

void init() {
	for (int i = 0; i <= MAX; i++) {
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
	que.push(node(u, 0));
	dis[u] = 0;
	times[u]++;
	vis[u] = true;
	while (!que.empty()) {
		node now = que.front(); que.pop();
		vis[now.v] = false;
		for (int i = head[now.v]; ~i; i = e[i].next) {
			int v = e[i].to;
			int w = e[i].cost;
			if (dis[v] > dis[now.v] + w) {
				dis[v] = dis[now.v] + w;
				if (!vis[v]) {
					que.push(node(v, dis[v]));
					times[v]++;
					if (times[v] > n)
						return true;
				}
			}
		}
	}
	return false;
}

void judge(int u, int v, int w) {
	bool flag = true;
	for (int i = head[u]; ~i; i = e[i].next) {
		if (v == e[i].to) {
			if (w < e[i].cost) {
				e[i].cost = w;
				flag = false;
			}
		}
	}
	if (flag) {
		insert(u, v, w);
	}
}


int main() {
	init();

	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		judge(u, v, w);
		//judge(v, u, w);
	}

	if (SPFA(1)) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}

