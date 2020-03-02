#include<iostream>
#include<cstring>
using namespace std;

int a[100000 + 10];


int main(){
	int t;
	cin >> t;
	int count = 1;
	while(t--){
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int l = 1, r = 1, tl = 1, submax = -1000;
		int sum = -1000;
		for(int i = 1; i <= n; i++){
			int temp = a[i];
			if(a[i] > submax + a[i]){
				submax = a[i];
				tl = i;
			}else if(a[i] <= submax + a[i]){
				submax = submax + a[i];
			}
			if(sum < submax){
				sum = submax;
				l = tl; r = i;
			}
		}
		cout << "Case " << count << ":" << endl;
		cout << sum << " " << l << " " << r << endl;
		if(t >= 1) cout << endl;
		count++;
	}
	return 0;
} 
