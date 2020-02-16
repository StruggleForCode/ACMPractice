#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	int r, y, g;
	cin >> r >> y >> g;
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int k, t;
		cin >> k >> t;
		if (k == 0) {
			cnt += t;
		}
		if (k == 1) {			//没有问题
			int temp = cnt;
			/*cout << i << " " << temp << endl;
			cout << "HH" << endl;*/
			temp %= (r + y + g);
			if (temp <= t) {		
				cnt += t - temp;
			}
			else if (temp > t && temp <= t + g) {
				cnt += 0;
			}
			else if (temp > t + g && temp <= t + g + y) {
				cnt += r + y - (temp - t - g);
			}
			else if (temp > t + g + y) {
				cnt += r - (temp - t - g - y);
			}
			//cout << cnt << endl;
		}
		else if (k == 2) {			
			int temp = cnt;
			temp %= (r + y + g);
			/*cout << i << " " << temp << endl;
			cout << "HH" << endl;*/
			if (temp <= t) {
				cnt += temp + r;
			}
			else if (temp > t && temp <= t + r) {
				cnt += r + t - temp;
			}
			else if (temp > t + r && temp <= t + r + g) {
				cnt += 0;
			}
			else if (temp > t + r + g) {
				cnt += y - (temp - t - r - g) + r;
			}
			//cout << cnt << endl;
		}
		else if (k == 3) {
			int temp = cnt;
			temp %= (r + y + g);
			/*cout << i << " " << temp << endl;
			cout << "HH" << endl;*/
			if (temp <= t) {
				cnt += 0;
			}
			else if (temp > t && temp <= t + y) {
				cnt += r + y - (temp - t);
			}
			else if (temp > t + y && temp <= t + y + r) {
				cnt += r - (temp - t - y);
			}
			else {
				cnt += 0;
			}
			//cout << cnt << endl;
		}
	}
	cout << cnt << endl;
	return 0;
}
