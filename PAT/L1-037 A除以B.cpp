#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	if(b == 0){
		cout << a << '/' << b << '=' << "Error" << endl;
	}else if(b < 0){
		cout << a << '/' << '(' << b << ')' << '=';
		printf("%.2lf", a * 1.0 / b); 
	}else {
		cout << a << '/' << b << "=";
		printf("%.2lf", a * 1.0 / b); 
	} 
	return 0;
} 
