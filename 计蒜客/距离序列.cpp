#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 10000 + 5;

int n;
bool G[MAX][MAX];
bool vis[MAX];
int ans[MAX];
int w[MAX];

int match(int u){
	//vis[u] = true;
	for (int i = 0; i < n; i++){
		if(G[u][i] && !vis[i] && min(fabs(u - i), n - fabs(u - i)) == w[u]){
			cout << u << " " << i << " " <<  min(fabs(u - i), n - fabs(u - i)) << " " << ans[i] << endl;
			vis[i] = true;
			if(ans[i] == -1 || match(ans[i])){
				ans[i] = u;
				return true;
			}
		}
	}
	return false;
}

int hungury(){
	memset(ans, -1, sizeof(ans));
	int cnt = 0;
	for(int i = 0; i < n; i++){
		memset(vis, false, sizeof(vis));
		cnt += match(i);
		cout << "---" << cnt << endl;
	}
	return cnt;
}


int main(){
	cin >> n;
	memset(G, false, sizeof(G));
	for (int i = 0; i < n; i++){
		cin >> w[i];
		for (int j = 0; j < n; j++){
			if(min(fabs(i - j), n - fabs(i - j)) == w[i]){
				G[i][j] = 1;
				G[j][i] = 1;
				cout << i << " " << j << endl;
			}
		}
	}	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	int t = hungury();
	cout << t << endl;
	if(t != n){
		cout << "No Answer" << endl;
	} else{
			for (int i = 0; i < n; i++){
			cout << ans[i] << (i == n - 1 ? "\n" : " ");
		}
		int temp[MAX];
		for (int i = 0; i < n; i++){
			temp[ans[i]] = i;
		}
		for (int i = 0; i < n; i++){
			cout << temp[i] << (i == n - 1 ? "" : " ");
		}
	}
		
	return 0;
} 



/*
10
1 5 4 2 3 1 4 3 1 4

1 6 8 5 7 4 2 0 9 3

*/
