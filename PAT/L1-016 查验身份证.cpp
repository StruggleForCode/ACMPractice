#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int a[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2}; 
char M[11] =  {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

vector<string> ver;

int main(){
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		int sum = 0;
		for (int i = 0; i < s.size() - 1; i++){
			sum += a[i] * (s[i] - '0');
		}
		if(M[sum % 11] != s[s.size() - 1]){
			ver.push_back(s);
		}
	}
	if(ver.size() == 0){
		cout << "All passed" << endl;
	}
	else {
		for (int i = 0; i < ver.size(); i++){
			cout << ver[i] << endl;
		}
	}
	return 0;
}
