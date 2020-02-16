#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;


const int MAX = 100 + 5;

vector<int> ver[MAX];


int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		bool ok = true; 
		for (int j = 0; j < ver[u].size(); j++){
			if(ver[u][j] == v)
				ok = false;
		}
		if(ok){
			ver[u].push_back(v);
			ver[v].push_back(u);
		}
	} 
//	if(n * (n - 1) / 2 != m){
//		cout << "No" << endl;
//		return 0;
//	}
	for (int i = 1; i <= n; i++){
		if(ver[i].size() != n - 1){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
	return 0;
}
