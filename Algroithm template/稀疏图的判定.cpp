#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100 + 5;

//int map[MAX][MAX];


int main(){
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int u;
			cin >> u;
			if(u == 1 && i != j){
				ans++;
			}
		}
	}
	if(ans <= n * 10){
		cout << "Yes";
	}else cout << "No";
	
	return 0;
} 
