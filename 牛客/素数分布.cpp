#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
bool prim[3000];
 
void init(){
    memset(prim, true, sizeof(prim));
    prim[1] = false;
    prim[0] = false;
    for (int i = 2; i * i <= 2000; i++){
        if(prim[i]){
            for(int j = i * i; j <= 2000; j += i){
                prim[j] = false;
            }
        }
    }
         
}
 
 
int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if(prim[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
