#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool vis[10];

void dfs(int a[], int step, int n){
	if(step == n){
		for (int i = 0; i < n; i++){
			printf("%d", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = step; i < n; i++){
		swap(a[i], a[step]);
		dfs(a, step + 1, n);
		swap(a[i], a[step]);
	}
}


int main(){
	int n;
	cin >> n;
	memset(vis, false, sizeof(vis));
	dfs(a, 0, n);
	return 0;
}
