#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

typedef long long ll;
const int MAX = 1000000 + 5;

int a[MAX];

double cal(double l, double r, double a) {
	//cout << l << "  " << r << endl;
	if (r - l < 1e-6) {
		return r;
	}
	double mid = (l + r) / 2;
	if (mid + log(mid) < a) {
		l = mid;
	}
	else {
		r = mid;
	}
	double result = cal(l, r, a);
	return result;
}


int main() {
	double a;
	cin >> a;
	if (a >= 0) {
		a = cal(0, a, a);
	}
	else {
		a = cal(0, -a, a);
	}

	printf("%.6lf\n", a);
	return 0;
}
