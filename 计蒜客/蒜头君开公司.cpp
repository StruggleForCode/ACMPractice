#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10 + 5;

int task[MAX][MAX];

bool vis[MAX];
bool flag[MAX];
int n;

int ans = 1000000;

void dfs(int t, int sum){
	if(sum > ans){
		return;
	}
	if(t == n + 1){
		if(sum < ans)
			ans = sum;
	}
	for (int i = 1; i <= n; i++){
		if(!vis[i]){
			vis[i] = true;
			sum += task[t][i];
			//cout << sum << endl;
			dfs(t + 1, sum);
			sum -= task[t][i];
			vis[i] = false;
		}
	}
}



int main(){
	cin >> n;
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> task[i][j];
		}
	}
	
	memset(flag, false, sizeof(flag));
	memset(vis, false, sizeof(vis));
	
	dfs(1, 0);
	
	cout << ans << endl;
	return 0;
} 
