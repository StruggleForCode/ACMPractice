#include <iostream>
#include <cstring>
#include <queue>
#define N 100
using namespace std;
struct Location {
	int x;          /*定义变量下x, y用于储存点的坐标*/
	int y;
	int z;          //定义变量z, 用于储存转弯
	int last;
	Location(int _x = 0, int _y = 0, int _z = 0, int _last = 0) {
		x = _x;
		y = _y;
		z = _z;
		last = _last;
	}
	bool operator < (const Location &a) const {
		return z > a.z;
	}
};
char map[N][N];
int m, n, TIME;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
Location strat, END;
char flag[N][N];


int BFS(int x, int y) {
	flag[x][y] = true;
	priority_queue<Location> q;
	q.push(Location(x, y, 0, 0));
	while (!q.empty()) {
		Location livenote(0, 0, 0, 0), childnote(0, 0, 0, 0);
		livenote = q.top();
		q.pop();
		if (livenote.x == END.x && livenote.y == END.y) {
			return livenote.z;
		}
		for (int i = 0; i < 4; i++) {                    /*i = 0,向上；i = 1, 向下; i = 2, 向左；i = 3, 向右*/
			int a = dx[i] + livenote.x;
			int b = dy[i] + livenote.y;
			if (a < 0 || a >= m || b < 0 || b >= n || map[a][b] == '*' || flag[a][b])
				continue;
			childnote.x = a;
			childnote.y = b;
			childnote.last = i;
			//cout << livenote.last << endl;
			//cout << "--" << endl;
			//cout << livenote.z << endl;
			if(i != livenote.last)
				childnote.z = livenote.z + 1;
			else childnote.z = livenote.z;
			flag[a][b] = true;
			q.push(childnote);
			//cout << "hello world " << endl;
		}
	}
	return -2;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n >> TIME;
		memset(flag, false, sizeof(flag));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S') {
					strat.x = i;
					strat.y = j;
				}
				if (map[i][j] == 'P') {
					END.x = i;
					END.y = j;
				}
			}
		int t = BFS(strat.x, strat.y);
		//cout << t << endl;
		if (t <= TIME + 1 && t >= 0)
			cout << "YES" << endl;
		else {
			cout << "NO" << endl;
		}
		
	}
	return 0;
}


/*
6 5 1
P..**
*.**.
.....
S....
.....
*....


*/