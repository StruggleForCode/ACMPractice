#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define N 1000000
using namespace std;

int a[N];
int sum[N];

int main() {

	memset(a, 0, sizeof(a));
	memset(sum, 0, sizeof(sum));

	int n;

	cin >> n;

	int t = 1;
	a[0] = 1;
	for (int i = 1; i <= n; i++) {
		int m = 0;
		for (int j = 0; j < t; j++) {
			a[j] = a[j] * i + m;
			m = a[j] / 10;
			a[j] = a[j] % 10;
			if (m && t <= j + 1) {		// m != 0 Ö´ÐÐ
				t++;
			}
		}
		for (int j = 0; j < t; j++) {
			sum[j] += a[j];
			if (sum[j] > 9) {
				sum[j + 1]++;
				sum[j] -= 10;
			}
		}
	}

	int i;
	for (i = N; (i >= 0) && (sum[i] == 0); i--);
	for (; i >= 0; i--) {
		cout << sum[i];
	}
	
	cout << endl;


	return 0;
}