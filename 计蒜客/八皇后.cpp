#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20 + 5;

bool row[MAX], x1[MAX], x2[MAX];
int ans = 0;

bool check(int x, int y){
	return !row[x] && !x1[x + y] && !x2[x - y + 8];
}

void dfs(int c){
	if(c == 8){
		ans++;
		return;
	}
	for (int i = 0; i < 8; i++){
		if(check(i, c)){
			row[i] = x1[i + c] = x2[i - c + 8] = true;
			dfs(c + 1);
			row[i] = x1[i + c] = x2[i - c + 8] = false;
		}
	}
}


int main(){
	dfs(0);
	cout << ans << endl;
	return 0;
} 
