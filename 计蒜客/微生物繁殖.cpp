#include <iostream>
#include <vector>
using namespace std;


vector<pair<int, int> > g;


int main() {
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < 120; i++) {
		if (i % 2 == 1) {
			y -= x;
		}
		if (i % 6 == 0) {
			x *= 2;
		}
		if (i % 4 == 0) {
			y *= 2;
		}
	}
	cout << x << " " << y << endl;
	return 0;
}