#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#define N 1000
using namespace std;

const int INF = 1e7;

int n, m;
int map[N][N], dist[N], p[N];
bool flag[N];


void Dijkstra(int u) {
	for (int i = 1; i <= n; i++) {
		dist[i] = map[u][i];
		if (dist[i] < INF)
			p[i] = u;
		else p[i] = -1;
	}

	dist[u] = 0;
	flag[u] = true;
	for (int i = 0; i < n; i++) {
		int t = u, temp = INF;
		for (int j = 1; j <= n; j++) {
			if (!flag[j] && dist[j] < temp) {
				t = j;
				temp = dist[j];
			}
		}
		if (t == u)
			return;
		flag[t] = true;
	
		for (int j = 1; j <= n; j++) {
			if (!flag[j] && map[t][j] < INF)
				if (dist[j] > temp + map[t][j]) {
					dist[j] = temp + map[t][j];
					p[j] = t;
				}
				
		}

	}
}


void FindPath(int u) {

	stack<int> path;
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (x != -1) {
			path.push(x);
			x = p[x];
		}
		cout << "最短距离为" << dist[i] << ",  路径为： ";
		while (!path.empty()) {
			cout << path.top();
			path.pop();
			cout << " ";
		}
		cout << endl;
	}

}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		map[u][v] = min(map[u][v], w);
	}

	int st;
	cin >> st;
	Dijkstra(st);
	FindPath(st);
	for (int i = 1; i <= n; i++) {
		cout << "小明所在的位置为：" << st << ",  小明要去的地方为 " << i << ", 最短距离为" << dist[i] << endl;
	}
	return 0;
}