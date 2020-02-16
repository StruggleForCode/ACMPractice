#include <iostream>
using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		int ans = 1, temp = m % 10;
		while (n) {
			if (n % 2)
				ans = ans * temp % 10;
			temp = temp * temp % 10;
			n /= 2;
		}
		cout << ans << endl;
	}
	return 0;
}