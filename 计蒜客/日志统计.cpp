#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000 + 5;

struct node {
	int ts, id;
};

bool cmp(node a, node b) {
	if (a.id == b.id) {
		return a.ts < b.ts;
	}
	else {
		return a.id > b.id;
	}
}

node a[MAX];
vector<int> result;


int main() {
	int n, d, k;
	cin >> n >> d >> k;
	for (int i = 0; i < n; i++) {
		int ts, id;
		cin >> a[i].ts >> a[i].id;
	}
	sort(a, a + n, cmp);
	int tts = -1, tid = -1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (tid != a[i].id) {
			tid = a[i].id;
			tts = a[i].ts;
			cnt = 1;
		}
		else {
			if (cnt < k) {
				if (a[i].ts < tts + d) {
					cnt++;
				}
				if (cnt == k)
					result.push_back(a[i].id);
			}
			else cnt = 1;
		}
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}