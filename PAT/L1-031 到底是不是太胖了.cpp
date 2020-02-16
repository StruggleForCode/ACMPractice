#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int main(){
	int n;
	cin >> n;
	while(n--){
		double h, w;
		cin >> h >> w;
		double prefect = (h - 100) * 0.9 * 2;
		if(fabs(w - prefect) < prefect * 0.1){
			cout << "You are wan mei!" << endl;
		}else if(w < prefect){
			cout << "You are tai shou le!" << endl;
		}else cout << "You are tai pang le!" << endl;
	}
	return 0;
} 
