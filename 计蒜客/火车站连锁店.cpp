#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100000 + 5;

int n, m;
int a[MAX];

bool check(int x){
	int ans = 1;
	int d = a[0];
	for (int i = 1; i < n; i++){
		if(a[i] - d >= x){
			ans++;
			d = a[i];
		}
		if(ans == n){
			break;
		}
	}
	if(ans >= m){
		return true;
	}
	else return false;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int l = 1, r = 1e9 / m;
	int mid = 0;
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
 	cout << l - 1 << endl;
	return 0;
} 
