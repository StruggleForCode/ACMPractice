#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXV = 1000 + 5;
const int MAXN = 100 + 5;

int dp[MAXV];
int w[MAXN];
int v[MAXN];


int main() {
	int V, n;
	cin >> V >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = V; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}

	cout << dp[V] << endl;
	
	return 0;
}