#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	int hh, mm;
	char c;
	cin >> hh >> c >> mm;
	if(hh == 12 && mm == 0){
		cout << "Only 12:00.  Too early to Dang." << endl;
		return 0;
	}
	
	if(hh >= 0 && hh < 12) {
		if(hh < 10){
			cout << "Only 0" << hh; 
		}
		else cout << "Only " << hh;
		if(mm < 10)
			cout << ":0" << mm << ".  Too early to Dang." << endl;
		else cout << ":" << mm << ".  Too early to Dang." << endl;
		return 0;
	}
	
	int cnt = hh - 12;
//	if(cnt == 11){
//		cout << "Dang" << endl;
//	}
//	else{
		if(mm != 0) cnt++;
		for (int i = 0; i < cnt; i++){
			cout << "Dang";
		}
		cout << endl;
	//}
	return 0;
} 
