#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 3000;

int num1[MAX], num2[MAX], num3[MAX]; 


string mulit(string s1, string s2){
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(num3, 0, sizeof(num3));
	for (int i = s1.size() - 1, j = 0; i >= 0; i--){
		num1[j++] = s1[i] - '0'; 
	}
	for (int i = s2.size() - 1, j = 0; i >= 0; i--){
		num2[j++] = s2[i] - '0';
	}
	for (int i = 0; i < s1.size(); i++){
		for (int j = 0; j < s2.size(); j++){
			num3[i + j] += num1[i] * num2[j];
		}
	}
	for (int i = 0; i < s1.size() + s2.size() + 10; i++){
		if(num3[i] > 9){
			num3[i + 1] += num3[i] / 10;
			num3[i] %= 10; 
		}
	}
	int i = MAX;
	int j;
	for (i = MAX; i >= 0 && num3[i] == 0; i--);
	for (j = 0; j <= MAX && num3[j] == 0; j++);
	string s = "";
	if(i == 0){
		s = "0";
	}else{
		for ( ; i >= j; i--){
			s.push_back(num3[i] + '0');
		}
	}
	return s;

}


int main(){
	string s1, s2;
	int n;
	while(cin >> s1 >> n){
		int index = -1;
		string s = "";
		for (int i = 0; i < s1.size(); i++){
			if(s1[i] == '.'){
				index = i;
			}
			else {
				if(index == 0 && s1[i] == '0'){
					continue;
				}
				s.push_back(s1[i]);
			}
		}
		bool ok = false;
		if(index == -1){
			ok = true;
		}
		index = 6 - index - 1;
		int i;
		for (i = s1.size() - 1; i >= 0 && s1[i] == '0'; i--);
		index -= (s1.size() - i - 1);
		string sum = "1";
		for (int i = 0; i < n; i++){
			sum = mulit(sum, s);
		}
		if(ok){
			cout << sum << endl;
			continue;
		}
		index *= n;
		if(index >= sum.size()){
			cout << ".";
			for (int i = 0; i < index - sum.size(); i++){
				cout << "0";
			}
			cout << sum << endl;
		}
		else  {
			index = sum.size() - index - 1;
			for (int i = 0; i < sum.size(); i++){
				cout << sum[i];
				if(i == index){
					cout << ".";
				}
			}
			cout << endl;
		}
		
		
	}
	return 0;
}
