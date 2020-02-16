#include <iostream>
#include <string>
using namespace std;


int main(){
	string s;
	cin >> s;
	for (int i = s.length() - 4; i <= s.length() - 1; i++){
		cout << s[i];
	}
	cout << '-';
	for (int i = 0; i < s.length() - 5; i++){
		cout << s[i];
	}
	cout << endl;
	return 0;
}
