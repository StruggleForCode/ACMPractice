#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 100000+5
using namespace std;

const int INF = 1e6;

struct qNote {
	int to, cost;
	qNote(int _to = 0, int _cost = 0) :to(_to), cost(_cost) {}
	bool operator < (const qNote &a) const {
		return cost > a.cost;
	}
};

struct Edge {
	int to, cost;
	Edge(int _to = 0, int _cost = 0) :to(_to), cost(_cost) {}
};

vector<vector<Edge> > map(MAX);
int n, m, dist[MAX];
bool flag[MAX];


void addEdge(int from, int to, int cost) {
	/*for (int i = 0; i < map[from].size(); i++) {
		if (map[from][i].to == to) {
			cost = min(map[from][i].cost, to);
			map[from].push_back(Edge(to, cost));
			map[to].push_back(Edge(from, cost));
			return;
		}
	}*/
	map[from].push_back(Edge(to, cost));
	map[to].push_back(Edge(from, cost));
}

void Dijkstra(int start) {
	priority_queue<qNote> que;
	memset(dist, INF, sizeof(dist));
	memset(flag, false, sizeof(flag));	
	dist[start] = 0;
	que.push(qNote(start, 0));

	while (!que.empty()) {
		
		int s = que.top().to;
		que.pop();
		if (flag[s]) continue;
		flag[s] = true;
		for (int i = 0; i < map[s].size(); i++) {
			int t = map[s][i].to;
			int temp = map[s][i].cost;
			if (!flag[t] && dist[t] > dist[s] + temp) {
				dist[t] = dist[s] + temp;
				que.push(qNote(t, dist[t]));
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		vector<Edge> e;
		map[i].swap(e);
	}

}


int main() {
	int s, t;
	while (cin >> n >> m >> s >> t) {
		if (n == 0 && m == 0)
			break;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			addEdge(u, v, w);
		}

		/*for (int i = 0; i <= n; i++) {
			cout << i << " ";
			for (int j = 0; j <map[i].size(); j++) {
				cout << " " << map[i][j].to << " " << map[i][j].cost << ",";
			}
			cout << endl;
		}*/

		Dijkstra(s);
		cout << dist[t] << endl;
		/*for (int i = 1; i <= n; i++)
			cout << dist[i] << " ";
		cout << endl;*/
	}
	
	return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define N 1000
using namespace std;

const int INF = 1e7;

struct qNote {
int to, cost;
qNote(int _to = 0, int _cost = 0) :to(_to), cost(_cost) {}

// ctrl + j

bool operator < (const qNote &a) const {
return cost > a.cost;
}
};

struct Edge {
int to, cost;
Edge(int _to = 0, int _cost = 0) : to(_to), cost(_cost) {}
};

vector <Edge> map[N];
int m, n;
int dist[N];
bool flag[N];


void addEdge(int from, int to, int cost) {
map[from].push_back(Edge(to, cost));
}


void Dijkstra(int start) {

memset(dist, 10000, sizeof(dist));
memset(flag, false, sizeof(flag));

priority_queue<qNote> que;
que.push(qNote(start, 0));
dist[start] = 0;
while (!que.empty()) {
qNote u = que.top();
que.pop();
int t = u.to;
if (flag[t])  continue;
flag[t] = true;
for (int i = 0; i < map[t].size(); i++) {
int v = map[t][i].to;
int w = map[t][i].cost;
if (!flag[v] && dist[v] > dist[t] + w) {
dist[v] = dist[t] + w;
que.push(qNote(v, dist[v]));
}
}

}
}

int main() {
cin >> n >> m;
while (m--) {
int u, v, w;
cin >> u >> v >> w;
addEdge(u, v, w);
}


cout << endl;
for (int i = 1; i <= n; i++) {
cout << i << "   ";
for (int j = 0; j < map[i].size(); j++) {
cout << " " << map[i][j].to << " " << map[i][j].cost << " ";
}
cout << endl;
}
int st;
cin >> st;
Dijkstra(st);
for (int i = 1; i <= n; i++) {
cout << dist[i] << " ";
}
cout << endl;
return 0;
}
*/