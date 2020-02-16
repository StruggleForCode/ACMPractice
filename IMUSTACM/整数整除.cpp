#include <iostream>
using namespace std;
const int INF = 1000000007;


int gcd(long long int a, long long int b) {
	long long int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	if (a == 1)
		return 0;
	return a % INF;
}

int main() {


	long long int n;
	long long int sum = 0;
	while (cin >> n) {
		sum = 0;
		for (long long int i = 1; i <= n; i++) {
			/*cout << gcd(n, i) << endl;
			sum += gcd(n, i);
			sum %= INF;
			cout << "i=" << i << "sum = " << sum << endl;*/

			if (gcd(n, i)) {
				sum += i;
				sum %= INF;
			}
		}
		cout << sum << endl;
	}

	
	return 0;
}