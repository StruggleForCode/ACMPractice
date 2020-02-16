#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#define N 10000000
using namespace std;

//bool is_prime(int n) {
//	if (n == 1)
//		return false;
//	for (int i = 2; i < n; i++) {
//		if (n % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}

//int s_prime[N];
bool flag[N];
int prime[N];

//void is_prime() {
//	for (int i = 2; i < N; i++) {
//		s_prime[i] = 1;
//	}
//
//	for (int i = 2; i * i < N; i++) {
//		for (int j = i * i; j < N; j += i) {
//			s_prime[j] = 0;
//		}
//	}
//}

void is_prime() {
	
	int cnt = 0;
	flag[0] = true;
	flag[1] = true;
	for (int i = 2; i < N; i++) {
		if (!flag[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt; j++) {
			if (i * prime[j] > N)
				break;
			flag[i*prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}


int main() {
	is_prime();
	int n;
	cin >> n;
	set<string> se;
	

	while (n--) {
		int m;
		cin >> m;
		string s;
		cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		if (!flag[m]) {
			if (se.count(s)) {
				cout << "You've told me to remember it." << endl;	
			}
			else {
				se.insert(s);
				cout << "I've memorized it." << endl;
			}
		}
		else {
			if (se.count(s)) {
				cout << "I knew this word." << endl;
			}
			else {
				cout << "You didn't help me to memorize it." << endl;
			}
		}		
	}
	return 0;
}