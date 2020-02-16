#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


const int MAX = 10000;
int n;
int C[MAX];

int lowbit(int x){
	return x & (-x);
}

int getsum(int x){
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i)){
		res += C[i];
	}
	return res;
}


void update(int x, int v){
	for (int i = x; i <= n; i += lowbit(i)){
		C[i] += v;
	} 
}


int main(){
	cin >> n;
	memset(C, 0, sizeof(C));
	for (int i = 1; i <= n; i++){
		int u;
		cin >> u;
		update(i, u);
	}
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << getsum(r) - getsum(l - 1) << endl;
	}
	return 0;
} 
