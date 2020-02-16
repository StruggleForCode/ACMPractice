#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;

char s[1000000];

int main(){
    int n;
    while(cin >> n){
        scanf("%s", s);
        int x = 0, t = 0, C = 0, p = 0, c = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            if(s[i] == 'x') x++;
            if(s[i] == 't' && t < x) t++;
            if(s[i] == 'C' && C < t) C++;
            if(s[i] == 'p' && p < C) p++;
            if(s[i] == 'c' && c < p) c++;
            if(x && t && C && p && c){
                ans++;
                x--; t--; C--; p--; c--;
            }
        }
        cout << ans << endl;
        }
    return 0;
} 
