#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

bool check(string s){
	int ok = true;
	for (int i = 0; i < s.size(); i++){
		if(s[i] < '0' || s[i] > '9'){
			ok = false;
			break;
		}
	}
	return ok;
}


int main(){
	string  s, s1, s2;
	cin >> s1 >> s2;
	bool ok1, ok2;
	ok1 = ok2 = false;
	ll a, b;
	a = b = 0;
	if(check(s1)){
		ok1 = true;
		for (int i = 0; i < s1.size(); i++){
			a += s1[i] - '0';
			a *= 10;
		}
		a /= 10;
		if(a < 1 || a > 1000){
			ok1 = false;
		} 
	}
	if(check(s2)){
		ok2 = true;
		for (int i = 0; i < s2.size(); i++){
			b += s2[i] - '0';
			b *= 10;
		}
		b /= 10;
		if(b < 1 || b > 1000)
		ok2 = false;
	
	}

	if(ok1 && ok2){
		cout << a << " + " << b << " = " << a + b << endl;
	}else{
		if(ok1){
			cout << s1;
		}else cout << '?';
		cout << " + ";
		if(ok2){
			cout << s2;
		}else cout << '?';
		cout << " = ?";
		
	}
	return 0;
} 
