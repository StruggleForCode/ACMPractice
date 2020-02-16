#include <iostream>
#define N 10000
using namespace std;
const int INF = 1e9 + 7;
 
 
int main() {
 
    int n;
    while (cin >> n && n) {
        long long int a[N];
        a[1] = 1; a[2] = 2;
 
        for (int i = 3; i <= n; i++) {
            a[i] = 2 * a[i - 1] + 3 * a[i - 2] + i;
            a[i] %= INF;
        }
        cout << a[n] << endl;
         
    }
 
 
    return 0;
}
