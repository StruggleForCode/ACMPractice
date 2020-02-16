#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;


int main(){
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > que;
	for (int i = 0; i < n; i++){
		ll u;
		cin >> u;
		que.push(u); 
	}
	ll sum = 0;
	while(que.size() != 1){
		int temp = que.top(); que.pop();
		temp += que.top(); que.pop();
		sum += temp;
		//cout << temp << endl;
		que.push(temp);
	}
	cout << sum << endl; 
	
	return 0;
}sefe
