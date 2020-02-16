#include <iostream>
#include <algorithm>
using namespace std;



int main(){
	int a, b;
	cin >> a >> b;
	int t;
	cin >> t;
	int c, d;
	c = d = 0;
	bool ok = false;
	while(t--){
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		if(!ok){
			if(x + u == y && x + u == v){
				//cout << "ying" << endl;
				continue;
			}
			if(x + u == y){
				c++;
				a--;
			}else if(x + u == v){
				d++;
				b--;
			}
			if(a < 0 || b < 0){
			//	cout << "y" << endl;
				ok = true;
			}
			
		}
	}
	if(a < 0){
		cout << "A" << endl;
		cout << d << endl;
	}else{
		cout << "B" << endl;
		cout << c << endl; 
	}
	return 0;
} 
