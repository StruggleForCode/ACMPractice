#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;

int m, n;
int father[maxn];

int find(int u){
	return u == father[u] ? u : u = find(father[u]);
}

void merge(int u, int v){
	father[u] = father[find(v)];
}

void init(){
	for (int i = 0; i <= maxn; i++){
		father[i] = i;
	}
}



int main(){
	
	int n, m;
	while(cin >> n && n){
		cin >> m;
		init();
		while(m--){
			int u, v;
			cin >> u >> v;
			merge(u, v);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++){
			if(father[i] == i){
				ans++;
			}
		
		}
		ans--;
		cout << ans << endl;
	}
	return 0;
}
