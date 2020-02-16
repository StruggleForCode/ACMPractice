#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> ver;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u;
		cin >> u;
		ver.push_back(u);
	}

	sort(ver.begin(), ver.end());
	
	if (n % 2 == 0) {
		cout << ver[n / 2 - 1] << endl;
	}
	else cout << ver[n / 2] << endl;
	
	return 0;
}