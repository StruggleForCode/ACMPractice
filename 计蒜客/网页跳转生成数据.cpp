//网页跳转生成数据
#include <iostream>
#include <stack>
#include <string>
#include <time.h>
using namespace std;

int a[54] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'.', '/' };

int main() {

	freopen("test.txt", "w", stdout);
	int n;
	stack<string> s, s1;
	string str1[3] = { "Visit", "Back", "Forward" }, str2;
	int t = 10;
	srand(time(0));
	while (t--) {
		n = rand() % 100;
		cout << n << endl;
		while (n--) {
			int temp = rand() % 3;
			if (str1[temp] == "Visit") {
				int t = rand() % 30;
				str2 = "http://";
				while (t--) {
					str2 += a[rand() % 54];
				}
				cout << str1[temp] << " " << str2 << endl;
			}
			else if (str1[temp] == "Back") {
				cout << str1[temp] << endl;
			}
			else if (str1[temp] == "Forward") {
				cout << str1[temp] << endl;
			}
		}
	}
	return 0;
}
