#include <iostream>
using namespace std;

const int MAX = 20;
int mini = 1000000;
int map[MAX][MAX];
int vis[MAX];
int n;


void dfs(int start, int cnt, int sum){
	if(sum > mini){
		return;
	}
	if(cnt == n){
		sum += map[start][1];
		//cout << sum << " " << mini << endl;
		if(sum < mini){
			mini = sum;
		}
		return;
	}
	for (int i = 1; i <= n; i++){
		if(!vis[i]){
			sum += map[start][i];
		//	cout << sum << endl;
			vis[i] = true;
			dfs(i, cnt + 1, sum);
			vis[i] = false;
			sum -= map[start][i];
		}
	}
}



int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> map[i][j];
		}
	}
//	vis[1] = true;
	dfs(1, 0, 0);
	cout << mini << endl;
	return 0;
} 
