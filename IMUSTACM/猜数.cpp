#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int n;
	int max = 20000, min = -1;
	while (cin >> n) {
		string s;
		getchar();
		getline(cin, s);

		/*cout << "hello world" << endl;
		cout << n << " " << s << endl;*/
		if (s == "too high") {
			if (n < max)
				max = n;
		}
		else if (s == "too low") {
			if(n > min)
				min = n;
		}
		else if (s == "right on") {
			if ((max - min) <= 1) {
				cout << "Xiaoz is dishonest" << endl;
			}
			else cout << "Xiaoz may be honest" << endl;
			max = 20000;
			min = -1;
		}

	}
	return 0;
}