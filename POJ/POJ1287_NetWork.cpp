#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100000;

int n, m;
int father[MAX];

struct edge{
	int u, v, cost;
};
edge E[MAX];

bool cmp(edge a, edge b){
	return a.cost < b.cost;
}

int find(int u){
	return u == father[u] ? u : father[u] = find(father[u]);
}

void merge(int u ,int v){
	father[find(v)] = find(u);
}

void kru(){
	for (int i = 0; i <= n; i++){
		father[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < m; i++){
		if(find(E[i].u) != find(E[i].v)){
			merge(E[i].u, E[i].v);
			sum += E[i].cost;
		}
	}
	cout << sum << endl;
}

int main(){
	while(cin >> n && n){
		cin >> m;
		if(m == 0){
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < m; i++){
			cin >> E[i].u >> E[i].v >> E[i].cost;
		}
		sort(E, E + m, cmp);
		kru();
		
	} 
	return 0;
} 
