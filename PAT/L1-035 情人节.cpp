#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> ver;

int main(){
	string s;
	for (int i = 0; s != "."; i++){
		cin >> s;
		ver.push_back(s);
	}
	if(ver.size() > 14){
		cout << ver[1] << " and " << ver[13] << " are inviting you to dinner..." << endl;
	}else if(ver.size() <= 14 && ver.size() >= 3){
		cout << ver[1] << " is the only one for you..."  << endl;
	}else {
		cout << "Momo... No one is for you ..." << endl;
	}
	return 0;
} 
