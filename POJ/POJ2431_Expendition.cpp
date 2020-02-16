#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 10000 + 5; 

pair<int, int> par[MAX];

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.first < b.first;
}


int main(){
	int n, l, p;
	while(cin >> n){
		for (int i = 0; i < n; i++){
			cin >> par[i].first >> par[i].second;
		}
		cin >> l >> p;
		for (int i = 0; i < n; i++){
			par[i].first = l - par[i].first;
		}
		sort(par, par + n, cmp);
		par[n].first = l;
//		for (int i = 0; i <= n; i++){
//			cout << par[i].first << " " << par[i].second << endl;
//		}
		priority_queue<int> que;
		int pos = 0, ans = 0, tank = p;
		bool flag = true;
		for (int i = 0; i <= n; i++){
			int d = par[i].first - pos;
			while(tank - d < 0){
				if(que.empty()){
					flag = false;
					break;
				}
				tank += que.top();
				que.pop();
				ans++;
			}
			tank -= d;
			if(!flag)
				break;
			pos = par[i].first
			que.push(par[i].second);
		}
		if(flag){
			cout << ans << endl;
		}else{
			cout << -1 << endl;
		}
		
	}
	
	return 0;
} 
