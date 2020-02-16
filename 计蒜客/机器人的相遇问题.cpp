#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;


ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1; y = 0; return a;
	}
	ll d = exgcd(b, a % b, x, y);
	int t = x; x = y; y = t - a / b * y;
	return d;
}

int main() {
	ll x, y, m, n, l;
	cin >> x >> y >> m >> n >> l;
	ll a = (m - n + l) % l;
	ll b = (y - x + l) % l;
	ll gcd = exgcd(a, l, x, y);
	if (b % gcd) {
		cout << "Impossible" << endl;
	}
	else {
		l /= gcd;
		a /= gcd;
		b /= gcd;
		cout << (b * x % l + l) % l << endl;
	}
	return 0;
}