#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int a[100000 + 6];



int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << max(a[0], a[n - 1]) << " ";
	if(n % 2 != 0){
		cout << a[n / 2] << " "; 
	}else{
		int w = a[n/2] + a[n / 2 - 1];
		if(w % 2 == 0){
			cout << w / 2 << " ";
		}else{
			printf("%.1lf ", w * 1.0 / 2);
		}
	}
	cout << min(a[0], a[n - 1]) << endl;
	return 0;
} 
