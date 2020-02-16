#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int main(){
    string s;
    while(cin >> s){
        int m;
        cin >> m;
        ll sum = 0;
        int len = s.size();
        for (int i = 0; i < m; i++){
            int l, r;
            cin >> l >> r;
            sum += len - (r - l) + 1;
        }
        if(sum & 1){
            cout << "Alice" << endl;
        }else {
            cout << "Bob" << endl;
        }
        
    }
    return 0;
} 

