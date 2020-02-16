#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;




int main(){
	int n;
	cin >> n;
	string s = "";
	for (int i = 0; i < n; i++){
		char t; cin >> t;
		s.push_back(t);
	}
	string s1 = "";
	for (int i = 0; i < n; i++){
		string temp = s;
		reverse(s.begin(), s.end());
		if(temp < s){
			s1.push_back(temp[0]);
			s.erase(s.end() - 1);
			reverse(s.begin(), s.end());
		}else{
			s1.push_back(s[0]);
			temp.erase(temp.end() - 1);
			s = temp;
		}
	}
	for (int i = 1; i <= s1.size(); i++){
		cout << s1[i - 1];
		if(i % 80 == 0){
			cout << endl; 
		}
	}
	cout << endl;
	return 0;
}
 
