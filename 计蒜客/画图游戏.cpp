#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX_N = 15 + 5;

bool Havel_Hakimi(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		sort(arr + i, arr + n, greater<int>());
		if (arr[i] + i >= n) return false;
		for (int j = i + 1; j <= i + arr[i]; j++) {
			--arr[j];
			if (arr[j] < 0) {
				return false;
			}
		}
	}
	if (arr[n - 1] != 0) return false;
	return true;
}


int main() {
	int n;
	int arr[MAX_N];
	int arr1[MAX_N];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr1[i] = arr[i];
	}
	

	
	if (Havel_Hakimi(arr1, n)) {
		for (int i = 0; i < n; i++) {
			int ans = arr[i];
			int cnt = 0;
			int j;
			for (j = 0; j < n - 1; j++) {
				if (cnt < ans && i != j) {
					cout << 1 << " ";
					cnt++;
				}
				else cout << 0 << " ";
			}
			if (cnt < ans && i != j) {
				cout << 1;
			}
			else cout << 0;
			cout << endl;
		}
	}
	else cout << "None" << endl;

	return 0;
}