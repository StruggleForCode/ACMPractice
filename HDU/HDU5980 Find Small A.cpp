#include <iostream>
#include <bitset>
#include <string>
using namespace std;

string binary(int n){
    string s;
    for (int i = 31; i >=0; i--){
        if(n & (1 << i)){
            s += '1';
        }
        else s += '0';
    }
    return s;
}


int main(){
    int t;
    string temp = binary(97);
    string a;
    for (int i = 32 - 8; i <= 31; i++){
        a += temp[i];
    }
    //cout << a << endl;
    cin >> t;
    int cnt = 0;
    while(t--){
        int n;
        cin >> n;
        string s = binary(n); 
    //    string s; cin >> s;
    //    cout << s.size() << endl;
    //    cout << "hello" << endl;
        for (int i = 0; i < s.size(); i += 8){
            bool flag = true;
            for (int j = 0; j < 8; j++){
                if(a[j] != s[i + j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                //cout << i << endl;
                cnt++;
            }
        }
        
    }
    cout << cnt << endl;
    return 0;
} 



/*
01100001100001100001100001100001

10000110000110000110000110000110
*/
