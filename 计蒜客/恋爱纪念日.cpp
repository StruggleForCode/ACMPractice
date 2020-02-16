#include <iostream>
#include <string>
using namespace std;

int month[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void judge(int &y, int &m) {
	if (m > 12) {
		y++;
		m = 1;
	}
}


int main() {
	int y, m, d, k;
	cin >> y >> m >> d >> k;
	for (int i = 0; i < k; i++) {
		if (d < 28)
			d++;
		else if (d == 28) {
			if (m != 2)
				d++;
			else if (m == 2) {
				if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
					d = 0;
					m++;
				}
				else {
					d = 1;
					m++;
				}
			}
		}
		else if (d == 29) {
			if ((m == 2) && ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))) {
				d = 1;
				m++;
			}
			else d++;
		}
		else if (d == 30) {
			if (m == 1 || m == 3 ||m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				d++;
			}
			else {
				d = 1;
				m++;
				judge(y, m);
			}
		}
		else if (d == 31) {
			d = 1;
			m++;
			judge(y, m);
		}
	}
	cout << y << "-";
	if (m < 10)
		cout << "0" << m << "-";
	else cout << m << "-";
	if (d < 10)
		cout << "0" << d << endl;
	else cout << d << endl;
		
}
