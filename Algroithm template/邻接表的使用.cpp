#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000;

struct edge{
	int v, next;
};

edge E[MAX <<  1];

int eid;
int head[MAX];

void init(){
	memset(head, -1, sizeof(head));
	eid = 0;
}

void insertEdge(int u, int v){
	E[eid].v  = v;
	E[eid].next = head[u];
	head[u] = eid++;
}

int main(){
	init();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, u, v;
		cin >> a >> u >> v;
		insertEdge(u, v);
		if(a == 1){
			insertEdge(v, u); 
		}
	}
	for (int u = 0; u < n; u++){
		cout << u << ":";
		for (int i = head[u]; i != -1; i = E[i].next){
			cout << " " << E[i].v;
		}
		cout << endl;
	}
	return 0;
} 
