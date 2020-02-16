#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ll sum = 1;
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		int n;
		cin >> n;
		sum *= n;
		while (sum % 10 == 0) {
			cnt++;
			sum /= 10;
		}
		sum %= 1000000000;
	}
	cout << sum << endl;
	cout << cnt << endl;
	return 0;
}

/*

*/


/*

*/