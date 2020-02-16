#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
 
 
const int MAX_N = 100000 + 5;
const int MAX_M = 400000 + 5;
const int inf = 0x3f3f3f3f;
 
struct edge{
    int to, cost, next;
};
 
struct node{
    int v, w;
    node(int _v, int _w): v(_v), w(_w){}
    bool operator < (const node &a) const {
        return w > a.w;
    }
};
 
int n, m;
int head[MAX_N], eid;
int dis[MAX_N], vis[MAX_N];
edge e[MAX_M];
 
 
 
 
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
    memset(dis, inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
    priority_queue<node> que;
    que.push(node(start, 0));
    dis[start] = 0;
    while(!que.empty()){
        node now = que.top();
        que.pop();
        if(vis[now.v]){
            continue;
        }
        vis[now.v] = true;
        for (int i = head[now.v]; ~i; i = e[i].next){
            int v = e[i].to;
            int w = e[i].cost;
            int m = max(dis[now.v], w);
            if(dis[v] > m){
                dis[v] = m;
                que.push(node(v, dis[v]));
            }
        }
    }
     
}
 
int main(){
    while(cin >> n >> m){
        init();
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            insertEdge(u, v, w);
        }
        dij(1);
        cout << dis[n] << endl;
    }
    return 0;
}
