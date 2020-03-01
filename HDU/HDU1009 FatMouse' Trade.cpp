#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

struct node{
	double j, f;
	double p;
};

node a[1000 + 5];
bool cmp(node t, node b){
	return t.p > b.p;
}

int main(){
	int m, n;
	while(cin >> m >> n){
		if(m == -1 && n == -1) break;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++){
			cin >> a[i].j >> a[i].f;
			if(a[i].f == 0) a[i].p = 10000;
			else a[i].p = a[i].j/a[i].f; 
		}
		sort(a, a + n, cmp);
//		cout << "---" << endl;
//		for (int i = 0; i < n; i++){
//			cout << a[i].j << " " << a[i].f << endl;
//		}
		double sum = 0, del = m * 1.0;
		int cnt = 0;
		for(cnt = 0; cnt < n; cnt++){
			if(del >= a[cnt].f){
				sum += a[cnt].j;
				del -= a[cnt].f;
			}else{
				break;
			}
		}
		if(del > 0 && cnt < n){
			sum = sum + del / a[cnt].f * a[cnt].j;
		}
		printf("%.3lf\n", sum);
	}	
	return 0;
} 

/*
10 3
100 5
10 5
1 5
Ãâ·ÑÇé¿ö 
*/
