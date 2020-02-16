#include <iostream>
using namespace std;

typedef long long ll;

ll n, mi, ans;
bool ok = false;
int a[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int p[15] = {0};

void dfs(int index, int u, ll x){
	if(ok){
		return;
	}
	if(x == n){
		cout << x << endl;
		ok = true;
		for (int i = 0; i < 15; i++){
		cout << p[i] << " ";
		}
		return;
	}
	if(u == 15) return;
	for (int i = 1; i <= u; i++){
		x = x * a[index];
		cout << x << endl;
		if(x > n) return;
		p[index] = i++;
		dfs(index + 1, u, x);
		p[index]--;
	}
		
} 



int main(){

	cin >> n;
	dfs(0, 60, 1);
	for (int i = 0; i < 15; i++){
		cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}
