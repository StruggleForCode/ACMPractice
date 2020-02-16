#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200 + 5;
const int MAX_M = 1000 + 5;

struct edge{
	int u, v, w;
};

int father[MAX_N];
edge e[MAX_M];
int m, n;


bool cmp(edge a, edge b){
	return a.w < b.w;
}

int find(int u){
	return u == father[u] ? u : father[u] = find(father[u]);
}

int merge(int u, int v){
	father[find(v)] = find(u);
}

int kurus(){
	for (int i = 1; i <= n; i++){
		father[i] = i;
	}
	int w = 0;
	for (int i = 0; i < m; i++){
		if(find(e[i].u) != find(e[i].v)){
			merge(e[i].u, e[i].v);
		}
		if(find(1) == find(n)){
		//	cout << e[i].w << endl;
			return e[i]. w;
		}

	}
//	return w;
}


int main(){
	while(cin >> n >> m){
        //memset(e, 0, sizeof(e));
		for (int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			e[i].u = u; e[i].v = v; e[i].w = w;
		}
		sort(e, e + m, cmp);
		cout << kurus() << endl;
	}

	return 0;
}
