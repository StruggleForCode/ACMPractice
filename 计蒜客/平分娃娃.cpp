#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 6 * 20000 + 5;

long long int dp[MAX];
vector<long long int > w;
int m[7];

int main() {
	long long int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= 6; i++) {
		cin >> m[i];
		sum += i * m[i];
	}

	if (sum % 2 != 0) cout << "Can't be divided." << endl;
	else {
		for (int i = 1; i <= 6; i++) {
			int j;
			for (j = 1; m[i] >= j; j = j << 1) {
				w.push_back(j * i);
				m[i] -= j;
			}
			if(m[i])
				w.push_back(m[i] * i);
		}


		/*for (int i = 0; i < w.size(); i++) {
			cout << w[i] << " ";
		}*/

	
		
		for (int i = 0; i < w.size(); i++) {
			for (int j = sum / 2; j >= w[i]; j--) {
				dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
			}
		}
		if (dp[sum / 2] == (sum / 2)) {
			cout << "Can be divided." << endl;
		}
		else {
			cout << dp[sum / 2] << endl;
			cout << sum / 2 << endl;
			cout << "Can't be divided." << endl;
		}
	}
	return 0;
}

/*
5 4 6 10 9 9
5848 3938 19784 13506 12330 15595

*/