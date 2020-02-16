#include <iostream>
#include <string>
using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s.size() != 10) {
			cout << "NO" << endl;
			continue;
		}
		if (s[0] != 'L' || s[1] != 'Q') {
			cout << "NO" << endl;
			continue;
		}
		bool ok = false;
		for (int i = 2; i < s.size(); i++) {
			if (s[i] > 'A' && s[i] < 'Z') {
				ok = true;
				break;
			}
		}
		if (ok) {
			cout << "NO" << endl;
		}
		else cout << "YES" << endl;
	}
	return 0;
}


/*

6
LQ12345678
LQ123
QL12345678
QU12345678
LQ123LIJI4
LQJSKDDJFK

*/