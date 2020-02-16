#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	int cost, d, w;
};

node a[20];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].cost >> a[i].d >> a[i].w;
	}
	int ans = -1;
	for (int i = 1; i <= (1 << n); i++){
		int consume = 0;
		int res = 0;
		bool ok = false;
		for (int j = 0; j <= n; j++){
			if(i & (1 << j)){
				consume += a[j].cost;
				res += a[j].w;
				if(a[j].d == 0) ok = true; 
			}
		}
		if(!ok) continue;
		if(consume > 10) continue;
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
