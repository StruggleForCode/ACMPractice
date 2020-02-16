#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


const int MAX_N = 1000 + 5;
int ans[MAX_N], a[MAX_N];

int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--) {
		cin >> a[i];
	}
	int len = 1;
	ans[len] = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] >= ans[len]) {
			ans[++len] = a[i];
		}
		else {
			int pos = lower_bound(ans , ans + len, a[i]) - ans;
			ans[pos] = a[i];
		}
		/*for (int j = 1; j <= len; j++) {
			cout << ans[j] << " ";
		}
		cout << endl;*/
	}

	cout << len << endl;
	return 0;
}