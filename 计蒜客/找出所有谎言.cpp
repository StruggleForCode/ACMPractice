#include <iostream>
#include <algorithm>
#define MAX 50000 + 5
using namespace std;

int father[MAX], dist[MAX];
int Size[MAX];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		father[i] = i; dist[i] = 0; Size[i] = 0;
	}
}


int find(int x) {
	if (father[x] == x)
		return x;
	int y = find(father[x]);
	father[x] = y;
	dist[x] += dist[father[x]];
	dist[x] %= 3;
	return father[x];
}


int main() {
	int n, k;
	cin >> n >> k;
	init(n);
	int cnt = 0;
	while (k--) {
		int d, x, y;
		cin >> d >> x >> y;
		if (x > n || y > n || (d == 2 && x == y)) {
			cnt++;
			continue;
		}

		int tx = find(x);
		int ty = find(y);

		

		if (tx == ty) {
			if (d != (dist[x] + dist[y]) % 3 + 1) {
				cnt++;
				continue;
			}
		}
		else {
		//	dist[tx] = 0;
			father[tx] = ty;
			dist[tx] = dist[tx] + dist[ty] + d - 1;
			dist[tx] %= 3;
		}

		for (int i = 0; i <= n; i++) {
			cout << father[i] << " ";
		}
		cout << endl;
		for (int i = 0; i <= n; i++) {
			cout << dist[i] << " ";
		}
		cout << endl;
		cout << "-----------" << endl;
	}
	cout << cnt << endl;
	
	return 0;
}