#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int a[100000];

int main() {
	int m, n;
	cin >> m;
	while (m--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		int t = 1;
		a[0] = 1;
		for (int i = 0; i < n; i++) {
			int m = 0;
			for (int j = 0; j < t; j++) {
				a[j] = a[j] * 2 + m;
				m = a[j] / 10;
				a[j] = a[j] % 10;
				if (m && t <= j + 1) {
					t++;
				}
			}
		}

		for (int i = t - 1; i >= 0; i--) {
			cout << a[i];
		}
		cout << endl;

	}
	return 0;
}