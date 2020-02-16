#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100 + 10;
int a[MAX][MAX];
int b[MAX][MAX];
int c[MAX][MAX];

int main(){
	int ra, ca;
	cin >> ra >> ca;
	for (int i = 0; i < ra; i++){
		for (int j = 0; j < ca; j++){
			cin >> a[i][j];
		}
	}
	int rb, cb;
	cin >> rb >> cb;
	for (int i = 0; i < rb; i++){
		for (int j = 0; j < cb; j++){
			cin >> b[i][j];
		}
	}
	
	if(ca != rb){
		cout << "Error: " << ca << " != " << rb << endl;
		return 0;
	}
	for (int i = 0; i < ra; i++){
		for (int j = 0; j < cb; j++){
			c[i][j] = 0;
			for (int k = 0; k < ca; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	cout << ra << " " << cb << endl;
	for (int i = 0; i < ra; i++){
		for (int j = 0; j < cb; j++){
			cout << c[i][j] << (j == cb - 1 ? '\n' : ' ');
		}
	}
	
	return 0;
}
