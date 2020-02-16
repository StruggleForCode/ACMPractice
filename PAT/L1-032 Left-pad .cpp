#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int n; char c, a;
	cin >> n >> c;
	getchar();
	string s;
	getline(cin, s);
	if(s.size() < n){
		for (int i = 0; i < n - s.size(); i++){
			cout << c;
		}
		cout << s << endl;
	}else{
		for (int i = s.size() - n; i < s.size(); i++){
			cout << s[i];
		}
		cout << endl;
	}
	return 0;
}
