#include <iostream>
using namespace std;
int main() {
	char str[1000];
	int num;
	while (cin >> str >> num) {
		int sum = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			sum = sum * 10 + str[i] - '0';
			sum %= num;
		}
		cout << sum << endl;
	}
	return 0;
}
