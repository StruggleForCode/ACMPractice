#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

typedef long long ll;
const int MAX = 1000000 + 5;

inline int read(){
	int X = 0, w = 0;
	char ch = 0;
	while(!isdigit(ch)){
		w |= (ch == '-');
		ch = getchar();
	}
	while(isdigit(ch)){
		X = (X << 3) + (X << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w ? -X: X;
} 

int a[MAX];

bool col(int l, int r, int n){
	int mid;
	while(l <= r){
		//cout << mid << endl;
		mid = (l + r) >> 1;
		if(a[mid] == n){
			return true;
		}
		if(a[mid] > n){
			r = mid - 1;
		}else {
			l = mid + 1;
		}
	}
	return false;
}


int main(){
	int n = read();
	int s = read();
	for (int i = 0; i < n; i++){
		a[i] = read();
	}
	
	
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; a[i] * 2 < s; i++){
		if(col(i, n, s - a[i])){
			ans++;
		}
	} 
	cout << ans << endl;
	return 0;
}
