#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	string s;
	cin >> s;
	double m = 0;
	for (int i = 0; i < s.size(); i++){
		if(s[i] == '2'){
			m += 1;
		}
	}
	if(s[0] == '-'){
		m = m / (s.size() - 1) * 1.5;
	}else{
		m = m / s.size();
	}
	if((s[s.size() - 1] - '0') % 2 == 0){
		m = m * 2;
	}
	printf("%.2lf%\n", m * 100);
	return 0;
} 
