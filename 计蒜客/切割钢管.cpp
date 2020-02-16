#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 10000 + 5;

int a[MAX];

int n, k;

bool check(int x){
	int ans = 0;
	for (int i = n - 1; i >= 0; i--){
		ans += a[i] / x;
		//cout << ans << endl;
		if(ans >= k){
			return true;
		}
	}
	return false;
}


int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int r = 0, l = 1e8;
	int mid = 0;
	int mini = 0;
	while(r <= l){
		int mid = (r + l) >> 1;
		//cout << mid << endl;
		if(check(mid)){
			mini = mid;
			//cout << "H" << endl;
			r = mid + 1;
		}else{
			//mini = mid;
			l = mid - 1;
		}
	}
	
	cout << r - 1 << endl;

	
	return 0;
}
 
