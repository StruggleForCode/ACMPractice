#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = a + b + c + d;
        if(sum % 3 != 0){
            cout << -1 << endl;
            continue;
        }
        bool flag = false;
        if(a + b == c && c == d){
            flag = true;
        }
        if(a + c == b && b == d){
            flag = true;
        }
        if(a + d == b && b == c){
            flag = true;
        }
        if(b + c == a && a == d){
            flag = true;
        }
        if(b + d == c && c == a){
            flag = true;
        }
        if(c + d == a && a == b){
            flag = true;
        }
        if(flag) cout << sum / 3 << endl;
        else cout << -1 << endl;
    }
    return 0;
}
