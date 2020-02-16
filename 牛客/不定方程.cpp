#include <iostream>
#include <algorithm>
using namespace std;
 
long long gcd(long long a, long long b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}
 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        long long x, y;
        cin >> x >> y;
        if(gcd(x, y) != 1){
            cout << -1 << endl;
        }else cout << y << " " << x << " " << x * y << endl;
    }
    return 0;
}
