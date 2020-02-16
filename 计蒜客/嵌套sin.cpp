#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int MAX = 200 + 5;


int main() {
	string s[MAX];
	int n;
	cin >> n;
	s[1] = "sin(1";
	for (int i = 2; i <= n; i++) {
		string res;
		stringstream ss;
		ss << i;
		ss >> res;
		s[i] = s[i - 1] + "+" + "sin" + "(" +res;
	}
	for (int i = 1; i <= n; i++) {
		s[i] += string(i, ')');
	}
	/*for (int i = 1; i <= n; i++) {
		cout << s[i] << endl;
	}*/
	
	string g = "";
	g += string(n - 1, '(');
	for (int i = 1; i <= n; i++) {
		string res;
		stringstream ss;
		ss << n - i + 1;
		ss >> res;
		g += s[i] + "+" + res + (i == n ? "" : ")");
	}
	
	cout << g << endl;

	

	return 0;
}