#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


double check(double x){
	return x + log(x);
}


int main(){
	double a;
	cin >> a;
	double l = 0, r = fabs(2 * a);
	double mid = 0;
	while(l < r){
		if(fabs(check(mid) - a) < 1e-6)
			break;
	    mid = (l + r) / 2;
	    //cout << mid << endl;
		if(check(mid) > a){
			r = mid;
		}
		else {
			l = mid;
		}
	}
	printf("%.6lf\n", mid);
	return 0;
} 
