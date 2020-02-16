#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000;


int main(){
	int r, n;
	while(cin >> r >> n){
		if(r == -1 && n == -1)
			break;
		int a[MAX];
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		int i = 0, ans = 0;
		while(i < n){
			int t = a[i++];
			while(i < n && a[i] <= t + r){
				i++;
			}
			int p = a[i - 1];
			while(i < n && a[i] <= p + r){
				i++;
			}
			ans++;
		}
		cout << ans << endl;
		
	}
}
