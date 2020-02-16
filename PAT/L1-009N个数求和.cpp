#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MAX = 1000;
pair<ll, ll> par[MAX];


ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a % b);
} 

ll lcm(ll a, ll b){
	return a * b / gcd(a, b); 
}



int main(){
	ll n;
	cin >> n;
	ll lcm_max = 1;
	for (ll i = 0; i < n; i++){
		char c;
		cin >> par[i].first >> c >> par[i].second;
		lcm_max	= lcm(lcm_max, par[i].second);
	}
	
	ll sum = 0;
	for (ll i = 0; i < n; i++){
		sum += par[i].first * (lcm_max / par[i].second);
	}
	if(sum == 0){
		cout << 0 << endl;
		return 0;
	}
	bool ok = false;
	if(sum < 0){
		ok = true;
		sum = -sum;
	}
	if(ok)
			cout << "-";
	if(sum < lcm_max){
		ll t = gcd(sum, lcm_max);
		cout << sum / t << "/" << lcm_max / t << endl;
	}
	else if(sum % lcm_max == 0){
		cout << sum / lcm_max << endl;
	}else{
		cout << sum / lcm_max << " ";
		sum = sum % lcm_max;
		ll t = gcd(sum, lcm_max);
		cout << sum / t << "/" << lcm_max / t << endl;
	}
 
	return 0;
}
