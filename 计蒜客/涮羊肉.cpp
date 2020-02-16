#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
const int MAX = 1000 + 5;
const int inf = 0x3f3f3f;

struct node {
	int start;
	int end;
};

node a[MAX];

bool cmp(node a, node b) {
	return a.end < b.end;
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a[i].start = x; a[i].end = x + y;
		}
		sort(a, a + n, cmp);
		int cnt = 1, temp = a[0].end;
		for (int i = 1; i < n; i++) {
			if (a[i].end - temp >= m) {
				cnt++;
				temp = a[i].end;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}