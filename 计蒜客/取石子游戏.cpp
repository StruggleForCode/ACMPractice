#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//int gcd(int a, int b){
//	if(b == 0){
//		return a;
//	} 
//	return gcd(b, a % b);
//} 

 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, a, b;
		cin >> n >> a >> b;
		int gcd = __gcd(a, b);
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if(i % gcd == 0){
				ans++;
			}
		}
		if(ans % 2 == 0){
			cout << "suantou" << endl;
		}else {
			cout << "huaye" << endl;
		}
	}
	return 0;
}
