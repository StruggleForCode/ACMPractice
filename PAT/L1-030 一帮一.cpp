#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
using namespace std;

typedef pair<int, string> par;

deque<par > par0;
deque<par > par1; 
int num[60];

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
  	int t; string s;
  	cin >> t >> s;
  	num[i] = t;
  	if(t == 0){
  		par0.push_back(par(t, s));
	}
	if(t == 1){
		par1.push_back(par(t, s));
	}
  }
//  
// 	while(!par0.empty()){
// 		cout << par0.front().first << " " << par0.front().second << endl;
// 		par0.pop_front();
//	 }
//  	while(!par1.empty()){
//  		cout << par1.front().first << " " << par1.front().second << endl;
//  		par1.pop_front();
//	  }
	
//	cout << endl;
  for (int i = 0; i < n / 2; i++){
  	if(num[i] == 0){
  	//	cout << num[i] << endl;
  		cout << par0.front().second << " ";
  		par0.pop_front();
  		cout << par1.back().second << endl;	
  		par1.pop_back();
	  }
	  else if(num[i] == 1){
	  //	cout << num[i] << endl;
	  	cout << par1.front().second << " ";
	  	par1.pop_front();
	  	cout << par0.back().second << endl;
	  	par0.pop_back();
	  }
  }
  


  
  return 0;
}
