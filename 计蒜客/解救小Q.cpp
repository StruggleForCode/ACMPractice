#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 50 + 5;

struct Location {
	int x1, y1;
	int x2, y2;
	bool flag = false;
};

struct link {
	int curi, curj;
	int step;
	link(int _curi = 0, int _curj = 0, int _step = 0) : curi(_curi), curj(_curj), step(_step) {}
};

Location a[26];

char map[MAX][MAX];
bool flag[MAX][MAX];
int n, m;

link start, End;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int BFS(int x, int y) {
	queue<link> que;
	que.push(link(x, y, 0));
	flag[x][y] = true;
	while (!que.empty()) {
		link livenote, childnote;
		livenote = que.front();
		que.pop();
		if (livenote.curi == End.curi && livenote.curj == End.curj) {
			return livenote.step;
		}
		/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		cout << flag[i][j];
		}
		cout << endl;
		}
		cout << endl;*/
		for (int i = 0; i < 4; i++) {
			int curx = livenote.curi + dx[i];
			int cury = livenote.curj + dy[i];
			if (curx < 0 || curx >= n || cury < 0 || cury >= m || flag[curx][cury] || map[curx][cury] == '#')
				continue;
			//flag[curx][cury] = true;
			//cout << curx << "    " << cury << endl;
			if (map[curx][cury] >= 'a' && map[curx][cury] <= 'z') {
				int u = map[curx][cury] - 'a';
				if (a[u].x1 == curx && a[u].y1 == cury) {
					curx = a[u].x2; cury = a[u].y2;
				}
				else if(a[u].x2 == curx && a[u].y2 == cury){
					curx = a[u].x1; cury = a[u].y1;
				}
				childnote.curi = curx;
				childnote.curj = cury;
				childnote.step = livenote.step + 1;
				que.push(childnote);
				continue;
			}
			//cout << curx << "   " << cury << endl;
			childnote.curi = curx;
			childnote.curj = cury;
			childnote.step = livenote.step + 1;
			flag[curx][cury] = true;
			que.push(childnote);
		}

	}
	return -1;
}



int main() {

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < 26; i++) {
			a[i].x1 = a[i].x2 = a[i].y1 = a[i].y2 = 0;
			a[i].flag = false;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'L') {
					start.curi = i;
					start.curj = j;
					start.step = 0;
				}
				if (map[i][j] == 'Q') {
					End.curi = i;
					End.curj = j;
				}
				if (map[i][j] >= 'a' && map[i][j] <= 'z') {
					if (!a[map[i][j] - 'a'].flag) {
						a[map[i][j] - 'a'].x1 = i;
						a[map[i][j] - 'a'].y1 = j;
						a[map[i][j] - 'a'].flag = true;
					}
					else {
						a[map[i][j] - 'a'].x2 = i;
						a[map[i][j] - 'a'].y2 = j;
					}
				}
			}
		}

		//cout << a[0].x1 << " " << a[0].y1 << endl;
		//cout << a[0].x2 << " " << a[0].y2 << endl;
		memset(flag, false, sizeof(flag));

		int cnt = BFS(start.curi, start.curj);
		cout << cnt << endl;
	}

	return 0;
}


// 46 35


/*
8 7
....L.#
.######
b#b.a..
##.##..
.......
.......
.......
..Q.a..


2
5 5
....L
.###.
b#b#a
##.##
.Q..a
*/