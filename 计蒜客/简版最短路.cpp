#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 1000 + 5;
const int MAX_M = 10000 + 5;

struct edge {
	int v, next;
	int step;
};

edge p[MAX_M << 1];
int head[MAX_N], eid;
int dist[MAX_N];
bool flag[MAX_N];

void init() {
	memset(head, -1, sizeof(head));
	memset(dist, 0, sizeof(dist));
	memset(flag, false, sizeof(flag));
	eid = 0;
}

void addedge(int u, int v) {
	p[eid].v = v;
	p[eid].next = head[u];
	head[u] = eid++;
}

void bfs(int start) {
	flag[start] = true;
	queue<edge> que;
	edge temp;
	temp.v = start;
	temp.step = 0;
	dist[temp.v] = 0;
	que.push(temp);
	while (!que.empty()) {
		edge now = que.front();
		flag[now.v] = true;
		que.pop();
		for (int i = head[now.v]; i != -1; i = p[i].next) {
			if (!flag[p[i].v]) {
				edge child;
				child.v = p[i].v;
				child.step = now.step + 1;
				que.push(child);
				dist[child.v] = child.step;
				flag[p[i].v] = true;
			}
			
		}
	}
}

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	init();
	while (m--) {
		int from, to;
		cin >> from >> to;
		addedge(from, to);
		addedge(to, from);
	}
	bfs(c);
	for (int i = 1; i <= n; i++)
		cout << dist[i] << endl;
	return 0;
}