#include <iostream>
using namespace std;
const int maxn = 110;
int a[maxn];
int minv[4 * maxn];

void pushup(int id){
    minv[id] = min(minv[id << 1], minv[id << 1 | 1]);
}

void build(int id , int l, int r){
    if(l == r){
        minv[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushup(id);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
   	for (int i = 1; i <= n; i++){
   		cout << a[i] << " ";	
	}
	cout << endl;
	for (int i = 1; i <= n * 4; i++){
		cout << minv[i] << " ";
	}
	cout << endl;
    return 0;
}

/*
10
1 3 5 7 9 10 2 4 8 6

*/
