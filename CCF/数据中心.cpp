#include <iostream>
#include <algorithm>
#include <bit/stdc++> 
using namespace std;

const int maxn = 600000;

struct edge{
	int from, to, dis;
}E[maxn];

int n, m, root;
int father[maxn];

bool cmp(edge a, edge b){
	return a.dis < b.dis;
}

int find(int u){
	return u == father[u] ? u : u = find(father[u]);
}

void merge(int u, int v){
	//father[u] = father[find(v)];
	father[find(v)] = find(u); 
}

int kru(){
	for (int i = 0; i <= n; i++){
		father[i] = i;
	}
	int ans = 0, ant = 0;
	for (int i = 0; i < m; i++){
		if(ant == n - 1) break;
		int x = find(E[i].from);
		int y = find(E[i].to);
		if(x != y){
			merge(E[i].from, E[i].to);
			//father[x] = y;
			ans = E[i].dis;
			ant++;
		}
	}
	return ans;
}

int main(){
	//cin >> n >> m >> root;
	scanf("%d%d%d", &n, &m, &root);
	for (int i = 0; i < m; i++){
		scanf("%d%d%d", &E[i].from, &E[i].to, &E[i].dis);
	}
	sort(E, E + m, cmp);
	
	int k = kru();
	
//	cout << k << endl;
	printf("%d", k);
	
	return 0;
}

/*
4 5 1
1 2 3
1 3 4
1 4 5
2 3 8
3 4 2 

*/ 
