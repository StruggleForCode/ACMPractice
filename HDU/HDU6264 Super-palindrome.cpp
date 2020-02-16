#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 0;
        int a[26];
        int b[26];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < s.size(); i += 2){
            a[s[i] - 'a']++;
        }
        for(int j = 1; j < s.size(); j += 2){
            b[s[j] - 'a']++;
        }
        int odd = 0; int even = 0;
        for (int i = 0; i < 26; i++){
            if(a[i] > odd)
                odd = a[i];
            if(b[i] > even){
                even = b[i];
            }
        }
        //cout << odd << " " << even << endl;
        if(s.size() % 2 == 0){
            cout << (s.size() - odd - even) << endl;
        }else{
            cout << (s.size() / 2 - even) + (s.size() / 2 + 1 - odd) << endl;
        }
        
    }
    return 0;
} 
