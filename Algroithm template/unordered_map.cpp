#include <iostream>
#include <unordered_map>
#include <map> 
using namespace std;


int main(){
	
	unordered_map<int, string> mymap;
	mymap[10] = "zhang san";
	mymap[4] = "lisi";
	mymap[6] = "wangwu";
	mymap[2] = "zhaoshi";
	for (unordered_map<int, string>::iterator it = mymap.begin(); it != mymap.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	cout << "-------------------" << endl;
	map<int, string> mymap1;
	mymap1[10] = "zhangsan";
	mymap1[4] = "lisi";
	mymap1[6] = "wangwu";
	mymap1[2] = "zhaoshi";
	for (map<int, string>::iterator it = mymap1.begin(); it != mymap1.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	
	return 0;
}

