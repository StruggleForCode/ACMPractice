#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


const int MAX = 200000;
int maxv[4 * MAX];
int a[MAX];

void pushup(int id){
	maxv[id] = max(maxv[id << 1], maxv[id << 1 | 1]);
} 

void build(int id, int l, int r){
	if(l == r){
		maxv[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	pushup(id);
}

void update(int id, int l, int r, int x, int v){
	if(l == r){
		maxv[id] = v;
		return;
	}	
	int mid = (l + r) >> 1;
	if(x <= mid){
		update(id << 1, l, mid, x, v);
	}else{
		update(id << 1 | 1, mid + 1, r, x, v);
	}
	pushup(id);
}

int query(int id, int l, int r, int x, int y){
	if( x <= l && r <= y){
		return maxv[id];
	}
	int mid = (l + r) >> 1;
	int res = 0;
	if(x <= mid){
		res = max(res, query(id << 1, l, mid, x, y));
	}
	if(y > mid){
		res = max(res, query(id << 1 | 1, mid + 1, r, x, y));
	}
	return res;
}

int main(){
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	while(q--){
		char c;
		cin >> c;
		int u, v;
		cin >> u >> v;
		if(c == 'Q'){
			cout << query(1, 1, n, u, v) << endl;
		}else{
			update(1, 1, n, u, v);
		}
	}
	return 0;
}
