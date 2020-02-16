#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAX_N = 1000 + 5;
const int MAX_M = 5000 + 5;
const int inf = 0x3f3f3f;

struct edge {
	int to, cost, next;
};
int head[MAX_M], eid;

edge e[MAX_M];

void init() {
	memset(head, -1, sizeof(head));
	eid = 0;
}

void insertEdge(int u, int v, int w) {
	e[eid].to = v;
	e[eid].cost = w;;
	e[eid].next = head[u];
	head[u] = eid++;
}

struct node {
	int dist;
	int to;
	node(int _dist, int _to) : dist(_dist), to(_to) {}
	bool  operator< (const node &a) const {
		return dist > a.dist;
	}
};

int n, m;
int dis[MAX_N];
int vis[MAX_N];

void Dijkstra(int u) {
 	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	priority_queue<node> que;
	dis[u] = 0;
	que.push(node(0, u));
	while (!que.empty()) {
		node now = que.top();
		//cout << now.dist << endl;
		que.pop();
		if (vis[now.to])
			continue;
		vis[now.to] = true;
		for (int i = head[now.to]; ~i; i = e[i].next) {
			int v = e[i].to;
			int w = e[i].cost;
			//cout << v << " " << w << endl;
			if (!vis[v] && dis[v] > dis[now.to] + w) {
				//cout << v << endl;
				dis[v] = dis[now.to] + w;
				que.push(node(dis[v], v));
			}
		}
	}
}

int main() {
	init();
	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		insertEdge(u, v, w);
		insertEdge(v, u, w);
	}

	Dijkstra(1);
	cout << dis[n] << endl;
	return 0;
}