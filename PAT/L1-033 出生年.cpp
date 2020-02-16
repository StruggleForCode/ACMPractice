#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int y, n;
	cin >> y >> n;
	int t = 0;
	for (int i = y; i <= 3000; i++){
		int temp = i;
		int a[10] = {0};
		int x = 4;
		while(x--){
			a[temp % 10]++;
			temp /= 10;
		}
		int cnt = 0;
		for (int j = 0; j < 10; j++){
			if(a[j] != 0){
				cnt++;
			}
		}
		if(cnt == n){
			t = i;
			break;
		}
	}
	cout << t - y << " ";
	if(t < 10){
		cout << "000" << t << endl;
	}else if(t < 100){
		cout << "00" << t << endl;
	}
	else if(t < 1000){
		cout << "0" << t << endl;
	}else cout << t << endl;
	return 0;
} 
