#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int n;
	cin >> n;
	long long sum = 0;
	int temp = 1;
	for (int i = 1; i <= n; i++){
		temp *= i;
		sum += temp;
	}
	cout << sum << endl;
	return 0;
} 
