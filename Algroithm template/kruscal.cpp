#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#define N 1000
using namespace std;


struct Note {
	int u;
	int v;
	int dist;
};

Note ver[N];

int n, m;
int father[N];
bool flag[N];


bool cmp(Note a, Note b) {
	return a.dist < b.dist;
}

int find(int u) {
	return u == father[u] ? u : find(father[u]);
}

void Union(int u, int v) {
	father[find(v)] = find(u);
}

int kruscal() {
	
	for (int i = 0; i < n; i++) {
		father[i] = i;
	}

	int sum = 0;

	for (int i = 0; i < m; i++) {
		if (find(ver[i].u) != find(ver[i].v)) {
			Union(ver[i].u, ver[i].v);
			sum += ver[i].dist;
		}
	}


	return sum;

}


int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ver[i].u = u;
		ver[i].v = v;
		ver[i].dist = w;
	}
	
	sort(ver, ver + m, cmp);
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << ver[i].u << " " << ver[i].v << " " << ver[i].dist << endl;
	}



	cout << endl << kruscal() << endl;
	
	

	


	return 0;
}