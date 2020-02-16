#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a < 60)
            cnt++;
    }
    cout << cnt * 400 << endl;
    return 0;
}
