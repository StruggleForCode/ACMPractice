#include <iostream>
#define MAX 30000 + 5
using namespace std;

int father[MAX], dist[MAX], Size[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		father[i] = i;
		dist[i] = 0;
		Size[i] = 1;
	}
}

int find(int x) {
	if (father[x] == x)
		return x;
	int y = father[x];
	father[x] = find(y);
	dist[x] += dist[y];
	return father[x];
}


void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		father[x] = y;
		dist[x] = Size[y];
		Size[y] += Size[x];
	}
}




int main() {
	int n;
	cin >> n;
	init();
	while (n--) {
		char ch;
		int n, m;
		cin >> ch >> n >> m;
		if (ch == 'M') {
			merge(n, m);
		}
		else {
			if (find(n) == find(m)) {
				cout << abs(dist[n] - dist[m]) - 1 << endl;
			}
			else cout << "-1" << endl;
		}
	}
	return 0;
}