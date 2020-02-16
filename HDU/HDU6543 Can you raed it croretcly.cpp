#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        if(s1 == s2){
            cout << "Equal" << endl;
            continue;
        }
        if(s1.size() != s2.size() || s1[0] != s2[0] || s1[s1.size() - 1] != s2[s2.size() - 1]){
            cout << "No" << endl;
            continue;
        }   
        int a[30], b[30];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i < s1.size() - 1; i++){
            a[s1[i] - 'a']++;
        }   
        for (int i = 1; i < s2.size() - 1; i++){
            b[s2[i] - 'a']++;
        }
        bool flag = true;
        for (int i = 0; i < 30; i++){
            if(b[i] != a[i]){
                flag = false;
                break;
            }
        }
        if(flag) cout << "Yes" << endl;
        else  cout << "No" << endl;
    } 
    return 0;
} 
