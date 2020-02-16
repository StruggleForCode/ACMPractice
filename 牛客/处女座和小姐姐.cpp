#include <iostream>
#include <cstring>
using namespace std;
 
const int MAX = 1000 + 5;
bool a[MAX];
 
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (m % 2 == 1) {
            cout << m * n - 2 << endl;
        }
        else {
            cout << (m - 1)  * n - 1 << endl;
        }
    }
     
    return 0;
}
