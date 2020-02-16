#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;


const int MAX = 50000;
int C[MAX];
int n;

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
	string s;
	cin >> s;
	
	while(s != "End"){
		if(s == "Query"){
			int l, r;
			cin >> l >> r;
			cout << getsum(r) - getsum(l - 1) << endl;
		}
		else if(s == "Add"){
			int u, v;
			cin >> u >> v;
			update(u, v);
		}else if(s == "Sub"){
			int u, v;
			cin >> u >> v;
			update(u, -v);
		}
		cin >> s;
	}
	return 0;
}
