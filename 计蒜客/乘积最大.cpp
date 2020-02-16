#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX = 100000 + 5;
const ll inf = 1000000009;

struct node {
	int num;
	bool mark;
};

bool cmp(node a, node b) {
	return a.num > b.num;
}

node a[MAX];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		if (m < 0) {
			a[i].num = -m;
			a[i].mark = false;
		}
		else {
			a[i].num = m; a[i].mark = true;
		}
	}
	sort(a, a + n, cmp);
	//for (int i = 0; i < n; i++) {
	//	cout << a[i].num << " " << a[i].mark << endl;
	//}
	
	int fu = 0;
	int index = -1;
	for (int i = 0; i < k; i++) {
		if (!a[i].mark) {
			fu++;
			index = i;
		}
	}
	ll sum = 1;
	if (index % 2 == 0) {
		for (int i = 0; i < k; i++) {
			sum *= a[i].num;
			sum %= inf;
		}
		cout << sum << endl;
	}
	else {
		for (int i = 0; i < k; i++) {
			if (index != i) {
				sum *= a[i].num;
				sum %= inf;
			}
		}
		if (!a[k].mark) {
			sum *= a[k].num;
			sum %= inf;
			sum *= a[index].num;
			sum %= inf;
		}
		else {
			if (!a[k + 1].mark) {
				sum *= a[k + 1].num;
				sum %= inf;
				sum *= a[index].num;
				sum %= inf;
			}
			else {
				int ind = -1;
				for (int i = k + 2; i < n; i++) {
					if (!a[i].mark) {
						ind = i;
						break;
					}
				}
				ll u = a[index].num * a[ind].num;
				ll v = a[k].num * a[k + 1].num;
				if (u > v) {
					u %= inf;
					sum *= u;
					sum %= inf;
				}
				else {
					v %= inf;
					sum *= v;
					sum %=inf;
				}
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}