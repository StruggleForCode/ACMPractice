#include <iostream>
using namespace std;

const int Max = 50 + 5;

long long int dp[Max];


int main() {

	int n;
	cin >> n;
	dp[1] = 3;
	dp[2] = 6;
	dp[3] = 6;
	for (int i = 4; i <= n; i++){
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}
	cout << dp[n] << endl;

	return 0;
}