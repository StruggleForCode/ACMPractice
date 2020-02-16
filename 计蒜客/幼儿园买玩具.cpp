#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ver[105];


int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		for (int j = 0; j < t; j++){
			int u; cin >> u;
			ver[i].push_back(u);
		}
	}
	int ans = -1;
	for (int i = 0; i <= (1 << k); i++){
		int res = 0;
		int cnt = 0;
		bool ok = true;
		int temp = i;
		bool toy[20];
		memset(toy, false, sizeof(toy));
		for (int j = 0; j <= k; j++){
			if(temp & (1 << j)){
				cnt++;
				toy[j + 1] = true;
			}
		}
		if(cnt !=  m){
			continue;
		}
	//	cout << temp << endl;
		for (int l = 0; l < n; l++){
			bool ok = true;
			for (int j = 0; j < ver[l].size(); j++){
				if(!toy[ver[l][j]]){
					ok = false;
					break;
				}
			}
			if(ok){
				res++;
			}
		}
		//cout << res<< endl;
		ans = max(ans, res);
		//cout << ans << endl;
	}
	cout << ans;
	return 0;
} 
