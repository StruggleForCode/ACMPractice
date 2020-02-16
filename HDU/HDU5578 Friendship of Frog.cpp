#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n = 0;
    while(t--){
        n++;
        string s;
        int ans = 10000;
        cin >> s;
        map<char, int> m;
        for (int i = 0; i < s.size(); i++){
            if(m.count(s[i])){
                int t = i -  m[s[i]];
                m[s[i]] = i;
                ans = min(ans, t);
            }else{
                m[s[i]] = i;
            }
        }
        cout << "Case #" <<  n << ": ";
        if(ans == 10000){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
} 
