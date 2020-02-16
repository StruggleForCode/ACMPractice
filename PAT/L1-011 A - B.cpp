#include <iostream>
#include <set>
#include <string>
using namespace  std;


set<char> b;


int main(){
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	for(int i = 0; i < s2.size(); i++){
		//if(s2[i] != ' '){
			b.insert(s2[i]);
		//}
	}
	for (int i = 0; i < s1.size(); i++){
//		if(s1[i] == ' '){
//			cout << s1[i];
//		}
//		else 
		if(!b.count(s1[i])){
			cout << s1[i];
		}
	}
	cout << endl;
	 
	return 0;
}
 
