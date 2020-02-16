#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000;

struct edge{
	int to, next;
};

int head[MAX];
int eid = 0;
edge E[MAX];
int degree[MAX];

void init(){
	memset(head, -1, sizeof(head));
	eid = 0;
}

void addEdge(int u, int v){
	E[eid].to = v;
	E[eid].next = head[u];
	head[u] = eid++; 
}

bool euler(int start){
	
}

int main(){
	int n, m;
	cin >> n >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	} 
	
	return 0;
} 
