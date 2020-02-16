#include <iostream>
#include <algorithm>
using namespace std;


int a[1000 + 5] = {0};

int main(){
	int n;
	cin >> n;
	while(n--){
		int k;
		cin >> k;
		while(k--){
			int u;
			cin >> u;
			a[u]++;
		}
	}
	int index_max = a[1];
	for (int i = 1; i <= 1000; i++){
		if(a[index_max] < a[i]){
			index_max = i;
		}
		if(a[index_max] == a[i]){
			index_max = max(index_max, i);
		}
	}
	cout << index_max << " " << a[index_max] << endl;
	
	return 0;
} 
