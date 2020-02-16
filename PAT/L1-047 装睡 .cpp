#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string s; int u, v;
		cin >> s >> u >> v;
		if(u < 15 || u > 20){
			cout << s << endl;
			continue;
		} 
		if(v < 50 || v > 70){
			cout << s << endl;
			continue;
		}
	}
	return 0;
}
