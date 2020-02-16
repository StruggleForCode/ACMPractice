#include <iostream>
using namespace std;
 
int main() {
 
    int duan = 3;
    int n, cnt = 0;
    while (cin >> n) {
        if (n == 7) {
            if (duan > 1)
                duan--;
        }
        else if (n == 1) {
            if (duan < 7) {
                duan++;
            }
        }
        cnt++;
        if (cnt == 10) {
            if (duan == 7) {
                cout << "666" << endl;
            }
            else cout << "777" << endl;
            cnt = 0;
            duan = 3;
        }
    }
 
 
    return 0;
}
