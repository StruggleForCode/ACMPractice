#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAX = 100000 + 5;

const ll mod = 10465138737;

int father[MAX];


int find(int u){
	return u == father[u] ? u : father[u] = find(father[u]);
}

void merge(int u, int v){
	father[find(v)] = find(u);
}

void init(){
	for (int i = 0; i < MAX; i++){
		father[i] = i;
	}
}


int main(){
	int n, m;
	init();
	cin >> n >> m;
	ll cnt = 1;
	int ans = 0;
	while(m--){
		int u, v;
		scanf("%d%d", &u, &v);
		for (int i = 0; i < n; i++){
			find(i);
		}
		if(find(u) == find(v)){
			ans++;
			cnt *= 2;
			cnt %= mod; 
		}else {
			merge(u, v);
		}
		printf("%lld\n", cnt - 1);
		
	}
	return 0;
}
