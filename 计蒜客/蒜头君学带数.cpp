#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX = 10000;
const int inf = 0x3f3f3f3f;

struct edge{
	int to, cost;
	int next;
}; 

struct node{
	int v, w;
	node(int _v, int _w): v(_v), w(_w){}
	bool operator < (const node other) const{
		return w > other.v;
	}
};

edge e[MAX << 1];
int m, n;
int dis[MAX], vis[MAX], eid, head[MAX];

void init(){
	memset(head, -1, sizeof(head));
	eid = 0;
}

void insertEdge(int u, int v, int w){
	e[eid].to = v;
	e[eid].cost = w;
	e[eid].next = head[u];
	head[u] = eid++;
}

void dij(int start){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	priority_queue<node> que;
	que.push(node(start, 0));
	dis[start] = 0;
	while(!que.empty()){
		node now = que.top();
		que.pop();
		if(vis[now.v])
			continue;
		vis[now.v] = true;
		for (int i = head[now.v]; ~i; i = e[i].next){
			int v = e[i].to;
			int w = e[i].cost;
			if(dis[v] > dis[now.v] + w){
				dis[v] = dis[now.v] + w;
				que.push(node(v, dis[v]));
			}
		}
	}
}

int main(){
	cin >> n >> m;
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		insertEdge(u, v, w);
		insertEdge(v, u, w);
	}
	dij(1);
	for (int i = 1; i <= n; i++){
		cout << dis[i] <<  " ";
	}
}
