#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define N 1000 + 5
using namespace std;
bool falg[N];

int main() {
	int n, m;
	
	while (cin >> n >> m) {
		memset(falg, false, sizeof(falg));
		int ans = 1;
		int j = 0;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		while (1) {
			for (int i = 1; i <= n; i++) {
				if (!falg[i]) {
					j++;
				}
				if (j == m) {
					falg[i] = true;
					j = 0;
					ans++;
				}

			}
			if (ans == n)
				break;
		}

		for (int i = 1; i <= n; i++) {
			if (!falg[i])
				cout << i << endl;
		}

	}
	
	return 0;
}