#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define N 1000
using namespace std;


vector <int> g[N], p[N];
vector <int> father(N);
vector <bool> flag(N, false);


int find(int u) {
	return u == father[u] ? u : find(father[u]);
}


void Union(int u, int v) {
	father[find(v)] = find(u);
}

void Tarjan(int u) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		Tarjan(v);
		Union(u, v);
	}
	flag[u] = true;
	
	for (int i = 0; i < p[u].size(); i++) {
		int v = p[u][i];
		if (flag[v]) {
			cout << "LAC (" << u << ", " << v << ")  = " << find(v) << endl;
		}
	}

}


int main() {

	int Note, Quiry, root, u, v;
	cin >> Note >> Quiry >> root;
	for (int i = 0; i < Note - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
	}
	for (int i = 0; i < Quiry; i++) {
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}

	for (int i = 0; i <= Note; i++) {
		father[i] = i;
	}


	Tarjan(root);

	return 0;
}

