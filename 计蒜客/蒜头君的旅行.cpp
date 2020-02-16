#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct edge{
	int  v, w;
	int next;
};

const int MAX_N = 20000 + 5;
const int MAX_M = 50000 + 5;
const int inf = 0x3f3f3f3f;
int n, m;
bool vis[MAX_N];
vector<int> ver;
int head[MAX_N];
int eid = 0;

edge E[MAX_M << 1];

void init(){
	memset(head, -1, sizeof(head));
	eid = 0;
}

void insertEdge(int u, int v, int w){
	E[eid].v = v;
	E[eid].w = w;
	E[eid].next = head[u];
	head[u] = eid++;
}



void dfs(int u){
	vis[u] = true;
	int temp = 0x3f3f3f3f, t = 0;
	for (int i = head[u]; i != -1; i = E[i].next){
		if(temp > E[i].w){
			temp = E[i].w;
			t = E[i].v;
		} 
	}
	if(vis[t]){
		return;
	}
	ver.push_back(t);
	dfs(t);
	
}


int main(){
	init();
	cin >> n >> m;
	memset(vis, false, sizeof(vis));
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		insertEdge(u, v, w);
		insertEdge(v, u, w);
	}
	
	ver.push_back(1);
	dfs(1);
	
	for (int i = 0; i < ver.size(); i++){
		cout << ver[i] << (i == (ver.size() - 1) ? '\n' : ' ');
	}
	
	
	return 0;
} 
