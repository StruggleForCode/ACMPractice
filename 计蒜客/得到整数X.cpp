#include <iostream>
#include <algorithm>
using namespace std;

int n, X;
int ans = 0;
int a[25];
bool used[25];

void dfs(int cnt, int x){
	if(cnt > n || x > X){
		return;
	}
	if(x == X){
//		for (int i = 0; i < n; i++){
//			if(used[i]){
//				printf("%d ", a[i]);
//			}
//		}
//		cout << endl;
		ans++;
		return;
	} 
	for (int i = cnt; i < n; i++){
		if(!used[i]){
			used[i] = true;
			x += a[i];
			dfs(i + 1, x);
			x -= a[i];
			used[i] = false;
		}
	}
}


int main(){
	cin >> n >> X;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
} 
