#include <iostream>
#define N 10000000
using namespace std;

int is_prime[N];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		is_prime[i] = 1;
	}

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[i] = 0;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (is_prime[i]) {
			cout << i << " ";
		}
	}
	
	return 0;
}