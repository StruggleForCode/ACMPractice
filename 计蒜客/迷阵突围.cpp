#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int MAX = 100000;
const int inf = 0x3f3f3f3f;

struct edge{
	int u, v, next;
	double w;
};

struct node{
	int v;
	double dis;
	node(int _v = 0, double _dis = 0): v(_v), dis(_dis){}
	bool operator <(const node other) const{
		return dis > other.dis;
	}
};

edge E[MAX << 1];
int n, m;
int head[MAX];
int eid;

double dist[MAX];
double dist1[MAX];
double dist2[MAX];
bool vis[MAX];

pair<int, int> par[MAX];

void init(){
	memset(head, -1, sizeof(head));	
	eid = 0;
}

void insertEdge(int u, int v, double w){
	E[eid].v = v;
	E[eid].w = w;
	E[eid].next = head[u];
	head[u] = eid++;
}

double caculate(int x1, int y1, int x2, int y2){
	return (double)sqrt((double)(x1 - x2)*(x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}

void dij(int u){
	for (int i = 0; i <= MAX; i++){
		dist[i] = dist2[i] = 1000000.0;
	}
	memset(vis, false, sizeof(vis));
	priority_queue<node> que;
	dist[u] = 0;
	//dist2[u] = 0;
	que.push(node(u, dist[u]));
	while(!que.empty()){
		node now = que.top();
		que.pop();
		if(vis[now.v])
			continue;
		vis[now.v] = true;
	//	if(dist2[now.v] < now.dis) continue;
 		for (int i = head[now.v]; i != -1; i = E[i].next){
			int v = E[i].v;
			double cost = E[i].w + dist[now.v];
			//cout << cost << " " <<  dist[v] << endl;
			if(dist[v] > cost){
				//cout << cost << " " <<  dist[v] << endl;
				swap(dist[v], cost);
				que.push(node(v, dist[v]));
			}
			if(dist2[v] > cost && dist[v] < cost){
				dist2[v] = cost;
				que.push(node(v, dist2[v]));
			}
		}
	}
	
}
 
int main(){
	init();
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> par[i].first >> par[i].second;
	}
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		double len = caculate(par[u].first, par[u].second, par[v].first, par[v].second);
		insertEdge(u, v, len);
		insertEdge(v, u, len); 
	}
	dij(1);
	
	printf("%.2lf", dist2[n]);
//	for (int i = 1; i <= n; i++){
//		cout << dist[i] << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= n; i++){
//		cout << dist2[i] << " ";
//	}
//	cout << endl;
//	dij(1);
//	for (int i = 1; i <= n; i++){
//		dist1[i] = dist[i];
//	}
//	dij(n);
//	for (int j = 1; j <= n; j++){
//		dist2[j] = dist[j];
//	}
//	double ans = 1000000.0;
//	for (int u = 1; u <= n; u++){
//		for (int i = head[u]; i != -1; i = E[i].next){
//			int v = E[i].v; double w = E[i].w;
//			if(dist1[u] + dist2[v] + w > dist1[n]){
//				ans = min(dist1[u] + dist2[v] + w, ans);
//			}
//		}
//	}
//	printf("%.2lf", ans);
	return 0;
}
