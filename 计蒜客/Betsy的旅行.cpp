#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

//视频三十分钟讲的很清楚， 自己可以在想一下 


const int MAX = 10;
bool map[MAX][MAX];
int last[MAX][MAX], n, ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= n;
}


void dfs(int x, int y, int cnt){
	if(x == n && y == 1){
		if(cnt == n * n) ans++;
		return;
	}
	map[x][y] = true;
	int dir = -1;
	for (int i = 0; i < 4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(in(xx, yy) && !map[xx][yy]){
			last[xx][yy]--;
			if(last[xx][yy] == 1){
				dir = i;
			}
		}
	}
	for (int i = 0; i < 4; i++){
		if(dir != -1 && dir != i) continue;
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(in(xx, yy) && !map[xx][yy]){
			bool ok = true;
			int r = 0;
			for (int j = 0; j < 4; j++){
				int ex = xx + dx[j];
				int ey = yy + dy[j];
				if(in(ex, ey) && !map[ex][ey]){
					if(last[ex][ey] < 2){
						ok = false;
						break;
					}
					else if(last[ex][ey] == 2){
						r++;
					}
				}
			}
			if(ok && r <= 1) dfs(xx, yy, cnt + 1);
		}
	}
	map[x][y] = false;
	for (int i = 0; i < 4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(in(xx, yy) && !map[xx][yy]){
			last[xx][yy]++;
		}
	}
}



int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			last[i][j] == 0;
			for (int k = 0; k < 4; k++){
				int xx = i + dx[k];
				int yy = j + dy[k];
				if(in(xx, yy)){
					last[i][j]++;
				}
			}
		}
	}
	
	memset(map, false, sizeof(map));
	last[n][1]++;
	dfs(1, 1, 1);
	cout << ans << endl;
	return 0;
}

