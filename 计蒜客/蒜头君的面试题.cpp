#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000;

int father[MAX], dist[MAX], size[MAX];

int find(int u){
	//return father[u] == u ? u : father[u] = find(father[u]);
	if(father[u] == u)
		return u;
	int y = father[u];
	father[u] = find(y);
	dist[u] += dist[y];
	return father[u];
}

int merge(int u, int v){
	u = find(u);
	v = find(v);
	if(u != v){
		father[u] = v;
		dist[u] = size[v];
		size[v] += size[u];
	}
}

int main(){
	
	return 0;
}

