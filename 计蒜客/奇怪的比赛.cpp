#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i <1024; i++) {
		int temp = i;
		int start = 10;
		for (int j = 1; j <= 10; j++) {
			if (temp & 1) {
				start = start << 1;
			}
			else {
				start -= j;
			}
			temp = temp >> 1;
		}
		if (start == 100) {
			temp = i;
			for (int j = 1; j <= 10; j++) {
				cout << (temp & 1);
				temp = temp >> 1;
			}
			cout << endl;
		}
			
	}
	return 0;
}