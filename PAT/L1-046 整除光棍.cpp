#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;


int main(){
	int x, s = 0, n = 0;
	cin >> x;
	while(s < x){
		s = s * 10 + 1;
		n++;
	}
	while(true){
		cout << s / x;
		s %= x;
		if(s == 0) break;
		s = s * 10 + 1;
		n++;
	}
	cout << " " << n << endl;
	return 0;
}
