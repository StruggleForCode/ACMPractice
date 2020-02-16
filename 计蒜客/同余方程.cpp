#include <iostream>
using namespace std;

typedef long long ll;

//ll exgcd(ll a, ll b, ll &x, ll &y) {
//	if (b == 0) {
//		x = 1; y = 0;
//		return a;
//	}
//	int d = exgcd(b, a % b, x, y);
//	int t = x; x = y; y = t - a / b * y;
//	return d;
//}

// 扩展欧几里得
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1; y = 0;
	}
	else {
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
}

//费马小定理      注意用费马小定理时p一定要是素数
ll pow_mod(ll a, ll b, ll p) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b = b >> 1;
	}
	return res;
}


void fermat(ll a, ll p) {
	cout << pow_mod(a, p - 2, p) % p << endl;
}


int main() {
	ll a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	cout << (x % b + b) % b << endl;
	//fermat(a, b);
	return 0;
}