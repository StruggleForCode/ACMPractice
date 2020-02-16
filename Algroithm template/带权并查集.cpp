#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 35000 + 10;

int father[MAX];
int dis[MAX];
int size[MAX];

int find(int x){
	if(father[x] == x)
		return father[x];
	int temp = father[x];
	father[x] = find(father[x]);
	dis[x] += dis[temp];
	return father[x];
}

int merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x != y){
		father[x] = y;
		dis[x] = size[y];
		size[y] += size[x];
	} 
}

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		for (int i = 0; i <= n; i++){
			father[i] = i; dis[i] = 0; size[i] = 1;
		}
		while(m--){
			char c;
			scanf(" %c", &c);
			if(c == 'T'){
				int x, y;
				scanf("%d %d", &x, &y);
				merge(x, y);
			}
			else if(c == 'Q'){
				int x;
				scanf("%d", &x);
				find(x);
				cout << dis[x] << endl;
			}
		}
	}
	return 0;
}

 
