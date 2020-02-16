#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAX = 1000000 + 5;

long long a[MAX];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		scanf("%d", &n); 
		long long int sum = 0;
		for (int i = 0; i < n; i++){
			//cin >> a[i];
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		if(sum < n){
			//cout << sum << endl;
			printf("%lld\n", sum);
			continue;
		}
		long long ave = sum / n;
		long long oper = 0;
		for (int i = 0; i < n; i++){
			if(a[i] > ave){
				oper += a[i] - ave;
			}
		}
		//cout << oper << endl;
		printf("%lld\n", oper);
		
	}
	return 0;
}

/*
4
3
1 1 0
4
2 2 2 2
3
0 1 4
1
1000000000

4
5
1 1 1 10 10
*/
