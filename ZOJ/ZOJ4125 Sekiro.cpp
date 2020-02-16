#include <iostream>
#include <algorithm>
using namespace std;


int main(){

	int t;
	int n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		if(k >  50) {
			if(n == 0){
				cout << 0 << endl;
			}else{
				cout << 1 << endl;
			}
		}
		else{
			while(k--){
				n = n / 2 + n % 2;
			}
			cout << n << endl;
		}
	}
	return 0;
} 
