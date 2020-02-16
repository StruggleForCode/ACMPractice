#include <iostream>
#include <algorithm>
#include <string>
#define N 5000
using namespace std;

int a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	string s;
	cin >> s;
	int t;
	cin >> t;
	while (t--) {
		int u;
		cin >> u;
		cout << a[u - 1] << endl;
	}
	return 0;
}