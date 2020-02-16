#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


const int MAX = 8000000 + 5;
bool prime[MAX];

void is_prime(int n){
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= n; i++){
		if(prime[i]){
			for (int j = i * i; j <= n; j += i){
				prime[j] = false;
			}
		}
	}
}


int main(){
	int l, r;
	cin >> l >> r;
	is_prime(r);
	vector<int> ver;
	//if(l <= 1) l = 2;
	for (int i = l; i <= r; i++){
		if(prime[i]){
			ver.push_back(i);
		}
	}
	if(ver.size() <= 1){
		cout << "There are no adjacent primes."; 
		return 0;
	} 
	int min = 0x3f3f3f3f, max = -1;
	int min_x = -1, min_y = -1, max_x = -1, max_y = -1;
	for (int i = 1; i < ver.size(); i++){
		if(ver[i] - ver[i - 1] < min){
			min = ver[i] - ver[i - 1];
			min_x = ver[i - 1]; min_y = ver[i];
		}
		if(ver[i] - ver[i - 1] > max){
			max = ver[i] - ver[i - 1];
			max_x = ver[i - 1]; max_y = ver[i];
		}
	}
	cout << min_x << "," << min_y << " are closest, " << max_x << "," << max_y << " are most distant.";
	return 0;
}
