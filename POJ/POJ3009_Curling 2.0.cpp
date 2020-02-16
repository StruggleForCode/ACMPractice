#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


typedef long long ll;
int map[25][25];
int temp[25][25];
int w, h;
int ans;
int dx[4] = {0, 0, -1, 1};		// вС0 ср1 ио2 об3  3 + 5 = 8 
int dy[4] = {1, -1, 0, 0};
bool ok = false;
bool flag[25][25];


bool in(int x, int y){
	return x >= 0 && x < h && y >= 0 && y < w;
} 

void dfs(int x, int y, int cnt){
	if(ok){
		return;
	}
	if(cnt > ans){
		return;
	}
	if(cnt > 10){
		return;
	}
	for (int i = 0; i < 4; i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(in(xx, yy) && map[xx][yy] != 1){
			while(in(xx, yy) && map[xx][yy] == 0){
				xx += dx[i];
				yy += dy[i];
			}
			if(!in(xx, yy)){
				continue;
			}
			if(map[xx][yy] == 3){
				if(ans > cnt){
					ans = cnt;
				}
				return;
			}
			if(map[xx][yy] == 1){
				map[xx][yy] = 0;
				cnt += 1;
				dfs(xx - dx[i], yy - dy[i], cnt);
				cnt -= 1;
				map[xx][yy] = 1;
			}
		}
	}
}

int main(){
	while(cin >> w >> h && w && h){
		memset(map, 0, sizeof(map));
		ans = 100;
		ok = false;
		int x = 0, y = 0;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> map[i][j];
				if(map[i][j] == 2){
					x = i; y = j;
				}
			}
		}
		map[x][y] = 0;
		dfs(x, y, 1);
		if(ans != 100){
			cout << ans << endl;
		}else cout << -1 << endl;
	}
	return 0;
}


/*

6 1
1 0 2 1 1 3
*/
