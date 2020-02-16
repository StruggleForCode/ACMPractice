#include <iostream>
#include <algorithm>
#include <vector>
#define N 1000
using namespace std;


struct Note {
	int u;
	int v;
	int ver;
};


Note map[N];
int father[N];
int n, m;


bool cmp(Note a, Note b) {
	return a.ver < b.ver;
}

int find(int u) {
	return u == father[u] ? u : find(father[u]);
}

void Union(int u, int v) {
	father[find(v)] = find(u);
}

int kruskal() {
	for (int i = 0; i <= n; i++) {
		father[i] = i;
	}
	int sum = 0;

	for (int i = 0; i < m; i++) {
		if (find(map[i].u) != find(map[i].v)) {
			Union(map[i].u, map[i].v);
			sum += map[i].ver;
		}
	}
	return sum;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		map[i].u = u;
		map[i].v = v;
		map[i].ver = w;
	}

	sort(map, map + m, cmp);
	
	for (int i = 0; i < m; i++) {
		cout << map[i].u << " " << map[i].v << " " << map[i].ver << endl;
	}

	cout << endl;
	cout << endl;
	cout << kruskal() << endl;
	return 0;
}



/*
5 7
0 1 3
0 4 1
1 2 5
1 4 4
2 3 2
2 4 6
3 4 7


11 
nice 
*/