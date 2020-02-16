#include <iostream>
#include <algorithm>
using namespace std;

string s[3] = {"JianDao", "ChuiZi", "Bu"};

int main(){
	int n;
	cin >> n; 
	int t = 0; 
	string str;
	while(cin >> str){
		if(str == "End")
			break;
		if(t == n){
			cout << str << endl;
			t = 0;
			continue;
		}
		t++;
		int cnt = 0;
		for (int i = 0; i < 3; i++){
			if(str == s[i]){
				cnt = i;
				break;
			}
		}
		cout << s[(cnt + 1) % 3] << endl;
	}
	return 0;
}
