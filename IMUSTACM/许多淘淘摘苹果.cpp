#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;

struct Note {
	int wight;
	int index;
	int value;
};

bool cmp1(Note a, Note b) {
	return a.wight < b.wight;
}

bool cmp2(Note a, Note b) {
	return a.index < b.index;
}

int apple[N];
Note taotao[N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> apple[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> taotao[i].wight;
		taotao[i].index = i;
		taotao[i].value = 0;
	}

	sort(apple, apple + n);
	sort(taotao, taotao + m, cmp1);

	int j = m -1;
	for (int i = n - 1; i >= 0; i--) {
		if (j < 0)
			j = m - 1;
		taotao[j].value += apple[i];
		j--;
	}
	sort(taotao, taotao + m, cmp2);
	for (int i = 0; i < m; i++) {
		cout << taotao[i].value << " ";
	}
	

	
	
	return 0;
}