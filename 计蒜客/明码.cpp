#include <iostream>
#include <algorithm>
using namespace std;


void binary(int a) {
	for (int i = 7; i >= 0; i--) {
		if (a & (1 << i)) {
			cout << 1;
		}
		else cout <<  " ";
	}
}




int main() {
	
	int a;
	int cnt = 0;
	while (cin >> a) {
		binary(a);
		cnt++;
		if (cnt == 2) {
			cout << endl;
			cnt = 0;
		}
	}
	return 0;
}