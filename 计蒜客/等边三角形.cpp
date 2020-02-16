#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 25;

int p[MAX];
int sum = 0;
bool ok = false;

void dfs(int l1, int l2, int l3, int cnt){
	if(ok){
		return;
	}
	if(l1 > sum || l2 > sum || l3 > sum){
		return;
	}
	if(l1 == sum && l2 == sum && l3 == sum){
		ok = true;
		return;
	}
	
	dfs(l1 + p[cnt], l2, l3, cnt + 1);
	dfs(l1, l2 + p[cnt], l3, cnt + 1);
	dfs(l1, l2, l3 + p[cnt], cnt + 1);
	
	
}

int main(){
	freopen("triangle.in", "r", stdin);
    freopen("triangle.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i];
		sum += p[i];
	}
	if(sum % 3 != 0){
		cout << "no" << endl;
		return 0;
	}
	sum /= 3;
	dfs(0, 0, 0, 0);
	if(ok){
		cout << "yes" << endl;
	}
	else cout << "no" << endl;
	return 0;
} 
