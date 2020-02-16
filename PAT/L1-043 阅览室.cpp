#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int calculate(string s1, string s2){
	int hh1, hh2, minute1, minute2;
	hh1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	hh2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	minute1 = (s1[3] - '0') * 10 + (s1[4] - '0');
	minute2 = (s2[3] - '0') * 10 + (s2[4] - '0');
	if(minute2 < minute1){
		if(minute2 != 0)
			minute2 += 60 - minute1 + 1;
		else minute2 += 60 -minute1;
		hh2--;
	}
	else{
		minute2 -= minute1;
	}
	return (hh2 - hh1) * 60 + minute2;
}


int main(){
//	string s1 = "19:23", s2 = "20:00";
//	cout << calculate(s1, s2);
//	
	int n;
	cin >> n;
	while(n--){
		int num; char c; string s;
		map<int, map<char, string> > m;
		int times = 0, cnt = 0;
		while(cin >> num >> c >> s){
			if(num == 0){
				break;
			}
			if(m.count(num)){
				if(c == 'E' && calculate(m[num]['S'], s) >= 0){
					cnt++;
					times += calculate(m[num]['S'], s);
					//cout << calculate(m[num]['S'], s) << endl;
				}
			}
			else{
				if(c == 'E'){
					continue;
				}
				m[num][c] = s;
			}
		}
		if(times ==  0 && cnt == 0){
			cout << 0 << " " << 0 << endl;
		}
		else cout << cnt << " " << times/cnt << endl;
	}
	return 0;
}
