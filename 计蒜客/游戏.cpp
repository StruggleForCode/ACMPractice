#include <iostream>
#include <algorithm>
using namespace std;


const int MAX = 1000000 + 5;

int a[MAX];
int b[MAX];


int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[a[i]]++;
	}
	
	int cnt = 1;	
	for (int i = 1; i < 1000000; i++){
		int ans = 0;
		for (int j = i; j < 1000000; j += i){
			ans += b[j];
			if(ans >= k) cnt = i;
		}
	}
	cout << cnt << endl;
	
	return 0;
} 
