#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {

	int n;
	map<char,int> map1;
	int value = 2, cnt = 0;
	for (char i = 'A'; i < 'Z'; i++) {
		if (i == 'Q')
			continue;
		if (!map1.count(i)) {
			if (cnt == 3) {
				value++;
				cnt = 0;
			}
			map1[i] = value;
			
		}
		cnt++;
	}

	/*for (map<char, int>::iterator it = map1.begin(); it != map1.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
*/
	cin >> n;
	map<string, int> map2;
	
	for (int i = 0; i < n; i++) {
		string str1;
		vector<int> str2;
		cin >> str1;
		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] >= '0' && str1[i] <= '9')
				str2.push_back(str1[i] - '0');
			else if (str1[i] >= 'A'&& str1[i] < 'Z') {
				str2.push_back(map1[str1[i]]);
			}
		}

		string str3 = "";
		for (int i = 0; i < str2.size(); i++) {
			if (i == 3)
				str3 += '-';
			str3 += str2[i] + '0';
		}
		
		//cout << "    " << str3 << endl;
		
		if (!map2.count(str3)) {
			map2[str3] = 1;
		}
		else map2[str3]++;
	}


	int ans = 0;
	for (map<string, int>::iterator it = map2.begin(); it != map2.end(); ++it) {
		if (it->second >= 2) {
			cout << it->first << " " << it->second << endl;
			ans++;
		}
	}
	if (ans == 0) {
		cout << "No duplicates." << endl;
	}
	return 0;
}


/*
310-1010 4
310-4466 2
487-3279 8
888-1200 2
888-4567 6
967-1111 2
*/