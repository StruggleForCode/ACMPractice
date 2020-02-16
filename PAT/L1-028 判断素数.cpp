#include <iostream> 
#include <math.h>
using namespace std;

//bool isPrime(int num)
//{
//	if (num == 0 || num == 1)
//		return false;
//	if (num == 2)
//		return true;
//	if (num % 2 == 0)
//		return false;
//	for (int i = 3; i <= sqrt(num); ++i)
//		if (num % i == 0)
//			return false;
//	return true;
//}


int main(){
	int n;
	cin >> n;
	while(n--){
		long long int m;
		cin >> m;
		bool isprime = false; 
		for (int i = 3; i * i < m; i++){
			if(m % i == 0){
				isprime = true;
				break;
			}
		}
		if(m == 0 || m == 1){
			isprime = true;
		}
		if(!isprime){
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
//		if(isPrime(m)){
//			cout << "Yes" << endl;
//		}else cout << "No" << endl;
	}
	return 0;
}
