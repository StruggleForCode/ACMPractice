#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 1000;
const int inf = 0x3f3f3f;
typedef long long ll;

struct edge {
	int to, next;
};

edge e[MAX];
int head[MAX], eid;
int disgree[MAX];

void init() {
	for (int i = 0; i < MAX; i++)
		head[i] = -1;
	eid = 0;
}

void insertEdge(int u, int v) {
	e[eid].to = v;
	e[eid].next = head[u];
	head[u] = eid++;
}

int n, m;

void topu() {
	queue<int> que;
	for (int i = 0; i <= n; i++) {
		if (disgree[i] == 0)
			que.push(i);
	}
	
	while (!que.empty()) {
		int now = que.front();
		cout << now << endl;
		que.pop();
		for (int i = head[now]; i != -1; i = e[i].next) {
			int t = e[i].to;
			disgree[t]--;
			if (disgree[t] == 0)
				que.push(t);
		}
	}

}



int main() {
	init();
	cin >> n >> m;
	memset(disgree, 0, sizeof(disgree));
	while (m--) {
		int u, v, w;
		cin >> u >> v;
		insertEdge(u, v);
		disgree[v]++;
	}
	topu();
	return 0;
}