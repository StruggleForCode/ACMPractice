#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100 + 5;

int n, m;
bool G[MAX][MAX];
bool vis[MAX];
int ans[MAX];

bool match(int u){
	vis[u] = true;
	for (int i = m + 1; i <= n; i++){
		if(G[u][i] && !vis[i]){
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
	for (int i = 1; i <= m; i++){
		memset(vis, false, sizeof(vis));
		//cout << "kjdsk" << endl;
		cnt += match(i);
		//cout << cnt << endl; 
	}
	return cnt;
}


int main(){
	cin >> m >> n;
	int a, b;
	memset(G, false, sizeof(G));
	while(cin >> a >> b){
		if(a == -1 && b == -1){
			break;
		}
		G[a][b] = 1;
		G[b][a] = 1;
	}
	
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++){
//			cout << G[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	int t = hungury();
	if(t == 0){
		cout << "No Solution!" << endl;
	} 
	else{
		cout << t << endl;
		for (int i = 1; i <= n; i++){
			if(ans[i] != -1){
				cout << ans[i] << " " << i << endl;
			} 
		}
	}
	
	return 0;
}
