#include <iostream>
using namespace std;

typedef long long ll;

int r, y, g;


// n 什么信号灯 m 开始时的还剩的秒 t 为到达的时间
int time(int n, int m, int t) {
	int wait = 0; 
	if (t <= m) {
		return m - t;
	}
	else {
		t %= (r + y + g);
		if (n == 1) {
			t -= m;
			if (t <= r + y)
				return t;
			else return 0;
			
		}
		else if (n == 2) {
			t -= m;
			t -= r;
			if (t < 0) {
				return t;
			}
			else if (t > r + g)
				return t - r - g;
		}
		else if (n == 3) {
			if (t > y + r && t < y + r + m)
				return 0;
			else if (t <= y + r) {
				return t;
			}
			else if (t > y + r + m) {
				return y + r;
			}
		}
		
	}
	
}


int main() {
	
	int n;
	cin >> r >> y >> g >> n;
	pair<int, int> ret;
	int cnt = 0;
	while (n--) {
		cin >> ret.first >> ret.second;
		if (ret.first == 0)
			cnt += ret.second;
		else cnt += time(ret.first, ret.second, cnt);
	}
	cout << cnt << endl;
	return 0;
}