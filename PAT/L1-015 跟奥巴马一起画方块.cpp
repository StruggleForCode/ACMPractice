#include <iostream>
using namespace std;


int main(){
	int n;
	char c;
	cin >> n >> c;
	int temp = n / 2;
	if(n % 2 == 1){
		temp += 1;
	}  
	for (int i = 0; i < temp; i++){
		for (int j = 0; j < n; j++){
			cout << c;
		}
		cout << endl;
	}
	return 0;
} 
