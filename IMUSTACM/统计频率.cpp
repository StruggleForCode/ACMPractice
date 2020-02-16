#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;




int main() {


	string s;
	int cnt = 0;
	map<string, int> save;
	while (getline(cin, s)) {
		if (!save.count(s)) {
			save[s] = 1;
		}
		else save[s]++;
		cnt++;
	}


	for (map<string, int>::iterator it = save.begin(); it != save.end(); it++) {
		cout << it->first << " " << fixed << setprecision(4) << (it->second * 1.0) * 100/cnt  << endl;
		//cout << it->first << " " << it->second << endl;
	}

	return 0;
}