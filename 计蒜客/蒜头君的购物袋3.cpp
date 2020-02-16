#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXV = 10000 + 5;
const int MAXN = 1000 + 5;

int dp[MAXV];
int w[MAXN];
int v[MAXN];


int main() {
	int V, n;
	cin >> n >> V;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = w[i]; j <= V; j++) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	
	
	cout << dp[V] << endl;
	
	return 0;
}