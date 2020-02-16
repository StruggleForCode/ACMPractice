#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

struct matrix {
	ll n, m;
	ll a[10][10];
};

matrix matrix_mtl(matrix A, matrix B, ll mod) {
	matrix temp;
	temp.n = A.n; temp.m = B.m;
	for (int i = 0; i < temp.n; i++) {
		for (int j = 0; j < temp.m; j++) {
			temp.a[i][j] = 0;
			for (int k = 0; k < B.n; k++) {
				temp.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
				temp.a[i][j] %= mod;
			}
		}
	}
	return temp;
}

matrix unit(int n) {
	matrix ret;
	ret.m = ret.n = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				ret.a[i][j] = 1;
			}
			else {
				ret.a[i][j] = 0;
			}
		}
	}
	return ret;
}

matrix matrix_pow(matrix A, ll p, ll mod) {
	matrix ret = unit(A.n);
	while (p) {
		if (p & 1) ret = matrix_mtl(ret, A, mod);
		A = matrix_mtl(A, A, mod);
		p >>= 1;
	}
	return ret;
}

int main() {
	ll n, m;
	cin >> n >> m;
	matrix A;
	A.n = A.m = 2;
	A.a[0][0] = 1; A.a[0][1] = 1; A.a[1][0] = 1; A.a[1][1] = 0;
	if (n < 2) {
		cout << 1 << endl;
	}
	else {
		matrix temp = matrix_pow(A, n - 2, m);
		matrix B;
		B.n = 2; B.m = 1;
		B.a[0][0] = 1;
		B.a[1][0] = 1;
		B = matrix_mtl(temp, B, m);
		cout << B.a[0][0] << endl;
	}
	return 0;
}