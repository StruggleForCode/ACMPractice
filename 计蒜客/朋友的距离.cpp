#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100 + 5;

int map1[MAX][MAX];
int map2[MAX][MAX];


int main(){
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> map1[i][j];
		}
	}
 	for (int i = 0; i < n; i++){
 		for (int j = 0; j < n; j++){
 			cout << max(map1[i][j], map1[j][i]) << (j == (n - 1) ? '\n' : ' ');
		 }
	 }
	
	return 0;
} 
