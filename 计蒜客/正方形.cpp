#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 20 + 5;
int a[MAX];
int vis[MAX];
int sum;
int n;
int l[5]; 
bool ok = false;


void dfs(int index, int cnt){
	if(index == 4){
		ok = true;
		return;
	}
	if(ok){
		return;
	}
	if(l[index] > sum){
		return;
	}
	if(l[index] == sum){
		dfs(index + 1, 0);
	}
	for (int i = cnt; i < n; i++){
		if(!vis[i]){
			vis[i] = true;
			l[index] += a[i]; 
			dfs(index, i + 1);
			l[index] -= a[i];
			vis[i] = false;
		}
	}
	
}



int main(){
	cin >> n;
	memset(l, 0, sizeof(l));
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % 4 != 0){
		cout << "No" << endl;
		return 0;
	}
	sum /= 4;
	dfs(1, 0);
	if(ok){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
	
}
