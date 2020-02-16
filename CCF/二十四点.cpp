#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAX = 10000 + 5;


vector<queue<string> > save(MAX);

int main(){	
	int t, n;
	cin >> t >> n;
	getchar();
	while(t--){
		for (int i = 0; i < n; i++){
			char c;
			while(scanf("%c", &c) != EOF){
				string s;
				if(c == '\n'){
					break;
				}else if(c == ' '){
					continue;
				}else{
					char b;
					cin >> b;
					s.push_back(c); s.push_back(b);
				//	cout << s << endl;
					save[i].push(s);
				}
				
			}
		}
		
//		for (int i = 0; i < n; i++){
//			while(!save[i].empty()){
//				cout << save[i].front() << " ";
//				save[i].pop();
//			}
//			cout << endl;
//		}
//		continue;
		int ant = 0;
		int ans = 0;
		bool flag = false;
		while(true){
			if(!save[ant].empty()){
				if(save[ant].front()[0] == 'S'){
					int c = save[ant].front()[1] - '0';
					if(c == ant){
						flag = true;
						break;
					}
					if(save[c].front()[1] == (ant + '0')){
						save[c].pop();
						save[ant].pop();
						ans = 0;
						continue;
					}
				}
			}
			ant++;
			ans++;
			if(ans > n){
				break;
			}
			ant %= n;
		}
		
		for (int i = 0; i < n; i++){
			if(!save[i].empty()){
				flag = true;
				while(!save[i].empty()){
					save[i].pop();
				}
			}
		}
		cout << flag << endl;
	} 
	return 0;
} 


/*


3 2
R1 S1
S0 R0
R1 S1
R0 S0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0 R0 R0 R0 R0

2 3
R1 S1 
R2 S0 R0 S2
S1 R1
R1
R2 S0 R0
S1 R1


*/
