#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main(){
	string s;
	cin >> s;
	int a[4];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < s.size(); i++){
		if(s[i] == 'G' || s[i] == 'g'){
			a[0]++;
		}
		if(s[i] == 'P'|| s[i] == 'p'){
			a[1]++;
		}
		if(s[i] == 'L' || s[i] == 'l'){
			a[2]++;
		}
		if(s[i] == 'T' || s[i] == 't'){
			a[3]++;
		} 
	}
	while(1){
		if(a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0){
			break;
		}
		if(a[0] != 0){
			cout << 'G';
			a[0]--;
		}
		if(a[1] != 0){
			a[1]--;
			cout << 'P';
		}
		if(a[2] != 0){
			a[2]--;
			cout << 'L';
		}
		if(a[3] != 0){
			a[3]--;
			cout << 'T' ;
		}
	}
	cout << endl;
	return 0;
} 
