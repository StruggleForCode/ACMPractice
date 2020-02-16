#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		res = res / n * (n - 1);
	}
	cout << res << endl;
	return 0;
}