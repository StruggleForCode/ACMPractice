#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;

ll mod = 1000000000 + 7;

ll pow(ll n, ll m, ll p){
	ll res = 1;
	n = n % p; m = m % p;
	while(m){
		if(m & 1) res = res * n % p;
		n = n * n % p;
		m = m >> 1;
	}
	return res % p;
} 


int main(){
	ll n, m;
	cin >> n >> m;
	cout << (pow(m, n, mod) - (pow(m- 1, n - 1, mod) * m % mod) + mod) % mod  << endl;
}


