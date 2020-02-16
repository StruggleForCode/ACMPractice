#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    int n, m;
    while (t--) {
        cin >> n >> m;
        if (n == m) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}
