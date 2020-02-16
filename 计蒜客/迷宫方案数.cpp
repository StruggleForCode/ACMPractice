#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


const int MAX = 20;
char map[MAX][MAX];
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}


int ans = 0;

void dfs(int x, int y){
	if(map[x][y] == 'e'){
		ans++;
		return;
	}
	map[x][y] = '#';
	for (int i = 0; i < 4; i++){
	//	cout << "hh" << endl;
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(in(xx, yy) && map[xx][yy] != '#'){
			dfs(xx, yy);
		} 
	}
	map[x][y] = '.';
}



int main(){
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> map[i][j];
			if(map[i][j] == 's'){
				x = i; y = j;
			}
		}
	}
	dfs(x, y);
	cout << ans << endl;
	return 0;
} 
