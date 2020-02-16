#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 5;
const int inf = 0x3f3f3f;

struct node {
	int u, v;
	int cost;
};

int father[MAX];
node a[MAX];
int n, m, root;

bool cmp(node a, node b) {
	return a.cost < b.cost;
}

int find(int u) {
	return u == father[u] ? u : father[u] = find(father[u]);
}

void merge(int u, int v) {
	father[find(v)] = find(u);
}

int kuscarl() {
	for (int i = 0; i <= n; i++) {
		father[i] = i;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (find(a[i].u) != find(a[i].v)) {
			merge(a[i].u, a[i].v);
			ans = max(a[i].cost, ans);
		}
	}

	return ans;
}

int main() {
	

	cin >> n >> m >> root;
	for (int i = 0; i < m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].cost;
	}
	sort(a, a + m, cmp);
	cout << kuscarl() << endl;
	
	return 0;
}