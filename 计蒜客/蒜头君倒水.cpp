#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int main(){
	double a, b;
	double x, y;
	ll k;
	cin >> a >> b >> x >> y >> k;
	while(k--){
		double tpa = a * x * 0.01;
		double tpb = b * y * 0.01;
		a = a - tpa + tpb;
		b = b - tpb + tpa; 
	}
	printf("%.2lf %.2lf", a, b);
	return 0;
}
