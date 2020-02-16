#include <iostream>
#include <vector>
#include <string>
#define N 100000
using namespace std;


int father[N];
int m, n;

int find(int u) {
	if (u == father[u])
		return u;
	else return find(father[u]);
}

void Union(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v)
		father[v] = u;
}

int main() {

	while (cin >> n && n) {
		cin >> m;
		for (int i = 1; i <= n; i++) {
			father[i] = i;
		}
		while (m--) {
			int u, v;
			cin >> u >> v;
			Union(u, v);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			//cout << father[i] << " ";
			if (father[i] == i)
				cnt++;
		}
		//cout << endl;
		cout << cnt - 1 << endl;
	}

	return 0;
}