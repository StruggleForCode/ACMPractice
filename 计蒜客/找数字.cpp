#include <iostream>
using namespace std;

int n;
bool ok = false;

void dfs(long long int x, int cnt){
	if(cnt >= 19){
		return;
	}
	if(ok){
		return;
	}
	if(x % n == 0){
		ok = true;
		cout << x << endl;
	}
	dfs(x * 10, cnt + 1);
	dfs(x * 10 + 1, cnt + 1);
}

int main(){
	cin >> n;
	dfs(1, 0);
	return 0;
}
