#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


typedef long long ll; 
vector<int> ver;

int num[15] = {0};


int main(){
	ll tel;
	cin >> tel;
	ll temp = tel;
	while(temp){
		int t = temp%10;
		ver.push_back(t);
		num[t] = 1;
		temp /= 10;
	}
	vector<int> v;
	for (int i = 10; i >= 0; i--){
		if(num[i] > 0){
			v.push_back(i);
		}
	}
	
	vector<int> index;
	for (int i = ver.size() - 1; i >=0; i--){
		for (int j = 0; j < v.size(); j++){
			if(ver[i] == v[j]){
				index.push_back(j);
				break;
			}
		}
	}
	
	cout << "int[] arr = new int[]{";
	for (int i = 0; i < v.size() - 1; i++){
		cout << v[i] << ",";
	}
	cout << v[v.size() - 1] <<  "};" << endl;
	cout << "int[] index = new int[]{";
	for (int i = 0; i < index.size() - 1; i++){
		cout << index[i] << ",";
	}
	cout << index[index.size() - 1] << "};" << endl;
	
	 
	return 0;
} 
