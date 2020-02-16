#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int m[105];
int temp[105];

int sum = 0;
vector<vector<int> > g(10000);

int main(){
	int n;
	cin >> n;
	int Max = 0;
	for (int i = 1; i <= n; i++){
		cin >> m[i];
		Max = max(Max, m[i]);
	}
	temp[1] = 0;
	for (int i = 2; i <= n; i++){
		temp[i] = temp[i - 1] + m[i];
	}
	for (int i = 0; i <= n; i++){
		cout << temp[i] << " ";
	}
	int cnt = 1;
	for (int i = 0; i < Max; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 1; k <= n; k++){
				g[i + temp[k]].push_back(cnt);
				cnt++;
			}
		} 
	}
	
	for (int i = 0; i < g.size(); i++){
		for (int j = 0; j < g[i].size(); j++){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
