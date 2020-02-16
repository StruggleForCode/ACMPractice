#include <iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int ji , ou;
	ji = ou = 0;
	for (int i = 0; i < n; i++){
		int u;
		cin >> u;
		if(u % 2 == 0){
			ou++; 
		}else ji++;
	}
	cout << ji << " " << ou << endl;
} 
