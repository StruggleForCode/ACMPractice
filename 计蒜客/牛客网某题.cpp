#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f;
const int MAX_N = 200 + 5;
const int MAX_M = 1000 + 5;

struct edge {
	int to, cost, next;
};

struct node {
	int to, dis;
	node(int _to = 0, int _dis = 0) :to(_to), dis(_dis) {}
	bool operator< (const node &other) const {
		return dis > other.dis;
	}
};

edge e[MAX_M];
int eid;
int head[MAX_N];
int dist[MAX_N];

void init() {
	memset(head, -1, sizeof(head));
	memset(dist, 0x3f, sizeof(dist));
	eid = 0;
}

void insertEdge(int from, int to, int cost) {
	e[eid].to = to;
	e[eid].cost = cost;
	e[eid].next = head[from];
	head[from] = eid++;
}

void dij(int start) {
	priority_queue<node> que;
	dist[start] = 0;
	que.push(node(start, dist[start]));
	while (!que.empty()) {
		node now = que.top();
		que.pop();
		int to = now.to;
		int MAX;
		for (int i = head[to]; i != -1; i = e[i].next) {
			MAX = max(dist[to], e[i].cost);
			if (dist[e[i].to] > MAX) {
				dist[e[i].to] = MAX;
				que.push(node(e[i].to, dist[e[i].to]));
			}
		}
	}
}



int main() {
	int n, m;
	while (cin >> n >> m) {
		init();
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			insertEdge(u, v, w);
		}
		dij(1);

		cout << dist[n] << endl;
	}
	return 0;
}