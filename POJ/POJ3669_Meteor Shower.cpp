#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 305;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int n;
int map[MAX][MAX];
bool vis[MAX][MAX];
bool flag[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct node{
	int x; int y;
	int times;
	node(int _x = 0, int _y = 0, int _times = 0): x(_x), y(_y), times(_times) {}
	bool operator <(const node &other) const{
		return times >  other.times;
	}
};


bool in(int x, int y){
	return x >= 0 && y >= 0;
}

int bfs(){
	priority_queue<node> que;
	que.push(node(0, 0, 0));
	memset(flag, false, sizeof(flag));
	flag[0][0] = true;
	int ans = -1;
	while(!que.empty()){
		node now = que.top();
		que.pop();
		if(!vis[now.x][now.y]){
			//cout << now.x << " " << now.
			ans = now.times;
			break;
		}
		for (int i = 0; i < 4; i++){
			int xx = dx[i] + now.x;
			int yy = dy[i] + now.y;
			if(in(xx, yy) && now.times + 1 < map[xx][yy] && !flag[xx][yy]){
				flag[xx][yy] = true;
				que.push(node(xx, yy, now.times + 1));
			}
		}
	}
	return ans;
}


 

int main(){
	int n;
	while(cin >> n){
		memset(map, 0x3f, sizeof(map));
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; i++){
			int x, y, t;
			cin >> x >> y >> t;
			map[x][y] = min(t, map[x][y]);
			vis[x][y] = true;
			for (int j = 0; j < 4; j++){
				int xx = x + dx[j];
				int yy = y + dy[j];
				if(in(xx, yy)){
					map[xx][yy] = min(t, map[xx][yy]);
					vis[xx][yy] = true; 
				} 
			}
		}
		cout << bfs() << endl;
	}
	return 0;
} 
