#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int a[10][10];
int ans = 0;

int check(int x, int y, int w){
	int xx = (x / 3) * 3;
	int yy = (y / 3) * 3;
	for (int i = xx; i < xx + 3; i++){
		for (int j = yy; j < yy + 3; j++){
			if(w == a[i][j]) return 0;
		}
	}
	for (int i = 0; i < 9; i++){
		if(w == a[x][i]) return 0;
		if(w == a[i][y]) return 0;
	}
	return 1;
}

void write(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << a[i][j] << " "; 
		}
		cout << endl;
	}
}

void dfs(int now){
	int x = now / 9;
	int y = now % 9;
	if(now == 81){
		ans++;
		write();
		cout << endl;
		cout << endl;
		return;
	}
	if(a[x][y])
		dfs(now + 1);
	else {
		for (int i = 1; i <= 9; i++){
			if(check(x, y, i)){
				a[x][y] = i;
				dfs(now + 1);
				a[x][y] = 0;
			}
		}
	}
}





int main(){
	
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> a[i][j];
		}
	}
	dfs(0);
	cout << ans << endl;
	return 0;
} 

/*
0 4 6 0 0 1 0 0 0 
7 0 0 3 5 0 0 0 1
0 0 5 0 0 0 3 0 4
0 0 0 0 8 0 0 0 5
0 3 0 2 1 0 0 0 0
5 0 9 0 0 0 0 0 2
2 0 0 6 0 0 5 1 0
1 0 0 5 0 2 0 0 0
0 0 3 0 0 0 2 0 7

*/
