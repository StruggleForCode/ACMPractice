#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 105;
const int MAX_M = 105;

struct Note {
	int v, next;
};

Note edge[MAX_N];
int cnt;
int head[MAX_N];
void init() {
	memset(head, -1, sizeof(head));
	cnt = 0;
}

void add(int u, int v) {
	edge[cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main() {
	int n, m;
	cin >> n >> m;
	init();
	while (m--) {

		int x, y, a;
		cin >> a >> x >> y;
		add(x, y);
		if (a == 1) {
			add(y, x);
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = head[i]; j != -1; j = edge[j].next) {
			cout << " " << edge[j].v;
		}
		cout << endl;
	}

	return 0;
}