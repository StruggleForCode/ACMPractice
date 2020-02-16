#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int a[100+ 5];


int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n + 1; i++){
		cin >> a[i];
	}
	int temp = n;
	int i = 1;
	if(a[i] == 1){
		cout << 'x' << '^' << temp;
	}
	else if(a[i] == -1){
		cout << '-' << 'x' << "^" << temp;
	}else{
		cout << a[i] << 'x' << "^" << temp;
	}
	i++;
	temp--;
	for ( ; i <= n; i++){
		if(a[i] == 0){
			temp--;
			continue;
		}
		if(a[i] > 0){
			cout << '+';
		}
		
		if(a[i] == 1){
			if(i == n){
				cout << 'x';
			}
		    else cout << 'x' << '^' << temp;
		}
		else if(a[i] == -1){
			if(i == n){
				cout << "-x";
			}
			else cout << '-' << 'x' << '^' << temp;
		}
		else {
			if(i == n){
				cout << a[i] << 'x' ;
			} 
			else cout << a[i] << 'x' << '^' << temp;
		}
		temp--;
	}
	if(a[n + 1] == 0){
		return 0;
	}
	if(a[n + 1] > 0){
		cout << '+' << a[n + 1] << endl;
	}else cout << a[n + 1] << endl;
	
	return 0;
}

/*
7
-1 0 0 -1 -12 10 1 -10

8
8 0 0 0 0 0 0 0 0

8
-1 -2 -3 -4 -5 -6 -7 -8 -9

*/
 
