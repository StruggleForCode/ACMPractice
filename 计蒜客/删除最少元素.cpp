#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 1000 + 5;

int a[MAX_N];
int dp1[MAX_N], dp2[MAX_N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		dp1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] <= a[j]) {
				dp1[i] = max(dp1[j] + 1, dp1[i]);
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		dp2[i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] <= a[j]) {
				dp2[i] = max(dp2[j] + 1, dp2[i]);
			}
		}
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}
	cout << n - ans << endl;
	return 0;
}