#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 1000 + 5;


int main() {
	int n;
	int a[MAX_N], dp[MAX_N];
	int len;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	len = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] > dp[len]) {
			dp[++len] = a[i];
		}
		else {
			int pos = lower_bound(dp, dp + len, a[i]) - dp;
			cout << pos << endl;
			dp[pos] = a[i];
		}
	}
	
	cout << len << endl;
	return 0;
}


/*
8
2 1 5 3 6 4 6 3

6
2 4 1 4 6 3
*/