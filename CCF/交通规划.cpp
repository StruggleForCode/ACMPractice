#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
const int MAX_N = 10000 + 10;
const int MAX_M = 100000 + 10;
const int inf = 0x3f3f3f3f;

struct edge{
	int to, cost, next;
}E[MAX_M << 2];

struct node{
	int v, w;
	node(int _v, int _w):v(_v), w(_w){}
	bool operator <(const node &a) const{
		return w > a.w;
	} 
}; 

int head[MAX_N];
int dis[MAX_N], eid;
int vis[MAX_N];
int p[MAX_N];
int n, m;
int d = 0;

void init(){
	memset(head, -1, sizeof(head));
	eid = 0;
}

void insert(int u, int v, int w){
	E[eid].to = v;
	E[eid].cost = w;
	E[eid].next = head[u];
	head[u] = eid++;
}


void dij(int start){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	priority_queue<node> que;
	dis[start]  = 0;
	que.push(node(start, dis[start]));
	while(!que.empty()){
		node now = que.top();
		que.pop();
//		if(vis[now.v])
//			continue;
//		vis[now.v] = true;
		for (int i = head[now.v]; ~i; i = E[i].next){
			int v = E[i].to;
			int w = E[i].cost;
			if(dis[v] > dis[now.v] + w){
				dis[v] = dis[now.v] + w;
				//cout << w << endl;
				p[v] = w;
				que.push(node(v, dis[v]));
				continue;
			}
			if (dis[v] == dis[now.v] + w){
				p[v] = min(p[v], w);
			}
		}
	}
	
}



int main(){
	init();
	cin >> n >> m;
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		insert(u, v, w);
		insert(v, u, w);
	}
	dij(1);
	for (int i = 1; i <= n; i++){
		d += p[i];
		//cout << p[i] << " ";
	}
	//cout << endl;
	cout << d << endl;
	return 0; 
	 
}
