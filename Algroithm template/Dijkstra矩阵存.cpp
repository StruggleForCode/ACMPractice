#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#define N 10000
using namespace std;
const int INF = 1e7;

int m, n, map[N][N], dist[N], p[N];
bool flag[N];


void Dijkstra(int u) {
	for (int i = 1; i <= n; i++) {
		dist[i] = map[u][i];
		if (dist[i] < INF) {
			p[i] = u;
		}
	}

	flag[u] = true;
	dist[u] = 0;

	for (int i = 0; i < n; i++) {
		int t = u, temp = INF;

		for (int j = 1; j <= n; j++) {
			if (!flag[j] && dist[j] < temp) {
				temp = dist[j];
				t = j;
			}
		}

		
		if (t == u)
			return;
		flag[t] = true;


		for (int j = 1; j <= n; j++) {
			if (!flag[j] && map[t][j] < INF && dist[j] > temp + map[t][j]) {
				dist[j] = temp + map[t][j];
				p[j] = t;
			}
		}

	}

}

int main() {


	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++)
			flag[i] = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = INF;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			map[u][v] = min(map[u][v], w);
			map[v][u] = min(map[v][u], w);
		}
		int start = 1;
		Dijkstra(start);
		cout << dist[n] << endl;
	}
	
	

	return 0;
}