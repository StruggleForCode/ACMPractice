#include <iostream>
#include <cstring>
using namespace std;
 
const int MAX = 200000 + 5;
bool a[MAX];
 
 
int main() {
    int n;
    int pro = 1, next;
    cin >> n;
    memset(a, false, sizeof(a));
    for (int i = 0; i < n - 1; i++) {
        int u;
        cin >> u;
        a[u] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i])
            cout << i << endl;
    }
     
    return 0;
}
