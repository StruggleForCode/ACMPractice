#include <iostream>
#include <algorithm>
using namespace std;

int  main(){
	int n;
	cin >> n;
	while(n--){
		char c;
		double h;
		cin >> c >> h;
		if(c == 'F'){
			printf("%.2lf\n", h * 1.09);
		}
		if(c == 'M'){
			printf("%.2lf\n", h / 1.09);
		}
	}
	return 0;
} 
