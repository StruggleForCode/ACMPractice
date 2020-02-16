#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 50000 + 5;

struct edge {
	int v, next;
};

edge e[MAX_N << 1];
int head[MAX_N], eid;
int depth[MAX_N];
int father[MAX_N];



void init() {
	memset(head, -1, sizeof(head));
	for (int i = 0; i <= MAX_N; i++) {
		father[i] = i;
	}
	eid = 0;
}

void addedge(int u, int v) {
	e[eid].v = v;
	e[eid].next = head[u];
	head[u] = eid++;
}


bool flag[MAX_N];

void dfs(int u) {
	flag[u] = true;
	bool isleaf = true;
	for (int i = head[u]; i != -1; i = e[i].next) {
		if (!flag[e[i].v]) {
			dfs(e[i].v);
			isleaf = false;
			depth[u] = depth[e[i].v];
		}
	}
	if (isleaf) {
		depth[u] = 1;
	}
	else depth[u]++;
}



int main() {
	int n;
	cin >> n;
	int t = n;
	init();
	t--;
	while (t--) {
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		father[v] = u;
	}
	int ancentor = -1;
	for (int i = 1; i <= n; i++) {
		if (father[i] == i) {
			ancentor = i;
		}
	}
	vector<int> temp;
	for (int i = 0; i <= n; i++) {
		if (father[i] == ancentor && father[i] != i) {
			temp.push_back(i);
		}
	}
	dfs(ancentor);
	//cout << depth[temp[0]] + depth[temp[1]] << endl;
	vector<int> ant;
	for (int i = 0; i < temp.size(); i++) {
		int t = depth[temp[i]];
		ant.push_back(t);
	}
	sort(ant.begin(), ant.end());
	cout << ant[ant.size() - 1] + ant[ant.size() - 2] << endl;
	return 0;
}



