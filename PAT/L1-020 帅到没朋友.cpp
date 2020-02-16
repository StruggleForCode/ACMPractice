#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string, int> group;
set<string> que;

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		int temp = k;
		while(k--){
			string u;
			cin >> u;
			if(temp != 1){
				group[u] = temp;
			}
				
		}
	}
	int m;
	cin >> m;
	int cnt = 0;
	int i = 0;
	for (i = 0; i < m; i++){
		string u;
		cin >> u;
		if(!que.count(u) && (!group.count(u) || group[u] == 1)){
			cnt++;
			cout << u;
			que.insert(u);
			break;
		}
		que.insert(u);
	}
	for (; i < m - 1; i++){
		string u;
		cin >> u;
		if(!que.count(u) && (!group.count(u) || group[u] == 1)){
			cnt++;
			cout << " " << u;
		}
		que.insert(u);
	}
	

	
	
	if(cnt == 0){
		cout << "No one is handsome" << endl;
	}else cout << endl; 
	return 0;
} 
