#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;


ll gcd(ll a, ll b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
} 

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}


int main(){
	ll t;
	scanf("%lld", &t);
	while(t--){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", lcm(a, b));
	}
	return 0;
}
