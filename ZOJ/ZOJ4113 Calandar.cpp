#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

string str[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int main(){
	int t;
	cin >> t;
	while(t--){
		int y1, m1, d1;
		int y2, m2, d2;
		string s;
		cin >> y1 >> m1 >> d1 >> s;
		cin >> y2 >> m2 >> d2;
		int k =  fabs(m2 - m1);
	//	bool ok = d1 > d2 ? true : false;
		int sum = k * 30 + d2 - d1;
		int m = sum % 5;
		int pos = -1;
		for (int i = 0; i < 5; i++){
			if(s == str[i]){
				pos = i; break;
			}
		}
		pos += m;
		pos %= 5;
		cout << str[pos] << endl;
	}
	return 0;
}
