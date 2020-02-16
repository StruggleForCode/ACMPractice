#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 50;

int w, h;
char map[MAX][MAX];
bool flag[MAX][MAX];
int ans;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool in(int x, int y){
	return x >= 0 && x < h && y >= 0 && y < w;
}

void dfs(int x, int y){
	flag[x][y] = true;
	for (int i = 0; i < 4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(in(xx, yy) && !flag[xx][yy] && map[xx][yy] != '#'){
			ans++;
			dfs(xx, yy);
		}
	}
	//flag[x][y] = false;
}

int main(){
	while(cin >> w >> h && w && h){
		int x = -1, y = -1;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> map[i][j];
				if(map[i][j] == '@'){
					x = i; y = j;
				}
			}
		}
		memset(flag, false, sizeof(flag));
		ans = 0;
		dfs(x, y);
		cout << ans  + 1 << endl;
	}
	return 0;
} 
