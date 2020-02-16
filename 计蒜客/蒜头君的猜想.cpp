#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 8000000 + 5;

bool prime[MAX];
void is_prime(int n){
	memset(prime, true, sizeof(prime));
	for (int i = 2; i * i <= n; i++){
		if(prime[i]){
			for (int j = i * i; j <= n; j += i){
				prime[j] = false;
			}
		}
	}
}


int main(){
	int n;
	cin >> n;
	is_prime(n);
	int ans = 0;
	for (int i = 2; i <= n / 2; i++){
		if(prime[i] && prime[n - i]){
			ans++;
			//cout << i << " " << n - i << endl;
		}
	}
	cout << ans;

	return 0;
}
