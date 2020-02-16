#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


const int MAX = 10000;

int minv[MAX];

void pushup(int id){
	minv[id] = min(minv[id << 1], minv[id << 1 | 1]);
}

void build(int id, int l, int r){
	if(l == r){
		minv[id] = a[l];
		return;
	}
	int mid = (l + r) << 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	pushup(id);
}

void update(int id, int l, int r, int x, int v){
	if(l == r){
		minv[id] = v;
		return;
	}
	int mid = (l + r) >> 1;
	if(x < mid){
		update(id << 1, l, mid, x, v);
	}else{
		update(id << 1 | 1, mid + 1, r, x, v);
	}
	pushup(id);
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	return 0;
} 
