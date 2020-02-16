#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char a[1000][1000] = {' '};


int main(){
	int n;
	cin >> n;
	getchar();
	string s; 
	getline(cin, s);
	int len = s.size();
	int t = 0;
	if(len % n != 0){
		t = len / n + 1;
	}else t = len / n;
//	cout << t << endl;
	int pos = 0;
	for (int i = t; i > 0; i--){
		for (int j = 1; j <= n; j++){
			if(pos > s.size() - 1){
				continue;
			}
			a[j][i] = s[pos];
			pos++;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= t; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
} 
