#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;
const double PI = 3.1415926;

int main() {

	double x1, y1, z1, r1, x2, y2, z2, r2;
	cin >> x1 >> y1 >> z1 >> r1 >> x2 >> y2 >> z2 >> r2;
	double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
	if (d >= r1 + r2) {
		printf("%.7lf", 4.0 / 3 * PI * pow(r1, 3) + 4.0 / 3 * PI * pow(r2, 3));
	}
	else if (d <= max(r1, r2)) {
		if (d + min(r1, r2) < max(r1, r2)) {
			printf("%.7lf", 4.0 / 3 * PI * pow(max(r1, r2), 3));
		}
		else {
			cout << "0" << endl;
		}
	}



	return 0;
}

