#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 200000 + 5;
int maxv[MAX];
bool flag = false;
int w;
int h, n;

void pushup(int id){
	maxv[id] = max(maxv[id << 1], maxv[id << 1 | 1]);
}

void build(int id, int l, int r){
	if(l == r){
		maxv[id] = w;
		return;
	}
	int mid = (l + r) >> 1;
	build(id >> 1, l, mid);
	build(id >> 1 | 1, mid + 1, r);
	pushup(id);
}

void judge(int id, int l, int r, int x){
	if(l == r){
		maxv[id] -= x;
		flag = true;
		cout << x << endl;
		return;
	}
	int mid = (l + r) >> 1;
	if(maxv[id << 1] > x){
		judge(id >> 1, l , mid, x);
	}
	if(maxv[id << 1 | 1] >= x && !flag){
		judge(id >> 1 | 1, mid + 1, r, x);
	}
	pushup(id);
}


int main(){
	cin >> h >> w >> n;
	build(1, 1, h);
	int num;
	while(n--){
		cin >> num;
		flag = 0;
		if(maxv[1] >= num)
			judge(1, 1, h, num);
		if(!flag)
			cout << -1 << endl;
	}
	
	return 0;
}
