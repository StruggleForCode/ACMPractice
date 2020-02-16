#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;


ll check(ll n){
	ll sum = n;
	while(n){
		if(n < 4) break;
		int temp = n % 4;
		sum += n / 4;
		n = n / 4 + temp;
	}
	return sum;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		ll l = 0, r = n;
		ll mid = 0;
		while(l <= r){
			mid = (l + r) >> 1;
			if(check(mid) > n) r = mid - 1;
			if(check(mid) < n) l = mid + 1;
			if(check(mid) == n) break; 
		}
		cout << mid * m << endl;
	}
	return 0;
}
