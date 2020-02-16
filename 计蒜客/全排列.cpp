#include <iostream>
#include <algorithm>
using namespace std;

void dfs(int step, int a[]){
	if(step >= 7){
		for (int i = 0; i < 7; i++){
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = step; i < 7; i++){
		swap(a[i],  a[step]);
		dfs(step + 1, a);
		swap(a[i], a[step]);
	}
	
}


int main(){
	int a[7] = {1, 2, 3, 4, 5, 6, 7};
	int cnt = 1;
	dfs(0, a);
//	while(next_permutation(a, a + 7)){
//		for (int i = 0; i < 7; i++){
//			cout << a[i] << " ";
//		}
//		cout << endl;
//		cnt++; 
//	}
	
	return 0;
}
