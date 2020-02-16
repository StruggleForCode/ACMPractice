#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 20000 + 5;

int dp[MAX];
int w[35];


int main() {
	int v, n;
	cin >> v >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	/*for (int i = 0; i <= v; i++) {
		dp[i] = v;
	}*/

	for (int i = 0; i < n; i++) {
		for (int j = v; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
		}
	}

	cout << v - dp[v] << endl;

	return 0;
}