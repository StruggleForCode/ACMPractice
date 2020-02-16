#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;

int main() {
	ll x, y;
	cin >> x >> y;
	ll m = max(abs(x), abs(y));
	m--;
	ll sum = m * 9 + m * (m - 1) * 8 / 2 + 1;
	if (m + 1 == abs(x)) {
		cout << "hehe" << endl;
		if (x > 0) {
			if (y > 0) {
				sum += x * 3 + x - y;   // ok
			}
			else {
				sum += 4 * x - y;   // ok
			}
		}
		else {
			if (y > 0) {
				sum += y;		// ok
			}
			else {
				sum += y;		// ok
			}
		}
	}
	else if (m + 1== abs(y)) {
		cout << "enen" << endl;
		if (y > 0) {
			if (x > 0) {
				sum += 2 * y + x;		// ok
			}
			else {
				sum += 2 * y + x;		// ok
			}
		}
		else {
			if (x > 0) {
				sum += 6 * (-y) - x;
			}
			else {
				sum += 6 * (-y) - x;
			}
		}
	}
	cout << sum << endl;
	return 0;
}