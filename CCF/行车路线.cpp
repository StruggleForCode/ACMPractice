#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX_N = 1000;
const int MAX_M = 10000 + 5;


struct edge{
	int to, next;
}e[MAX_M << 1];

int head[MAX_N];
int eid;
int n, m;
int dis[MAX_N];
bool vis[MAX_N];
int map[MAX_N][MAX_N];

void init(){
	memset(head, -1, sizeof(head));
	eid = 0;
}

void insert(int u, int v){
	e[eid].to = v;
	e[eid].next = head[u];
	head[u] = eid++;
}


void dfs(int start, int to){
	vis[start] = true;
	for (int i = head[start]; i != -1; i = e[i].next){
		if(!vis[e[i].to]){
			map[start][e[i].to] = 1;
			map[e[i].to][start] = 1;
			dfs(e[i].to);
		}
	}
}







int main(){
	init();
	cin >> n >> m;
	while(m--){
		int u, v, w;
		cin >> u >> v;
		insert(u, v);
	}
	memset(map, 0, sizeof(map));
	
	for (int i = 1; i <= n; i++){
		memset(vis, false, sizeof(vis));
		dfs(i, i);
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << map[i][j] << " ";
		} 
		cout << endl;
	}
	return 0;
} 



/*
5 6
1 5
1 2
1 3
5 2
2 4
3 4
 
*/ 
