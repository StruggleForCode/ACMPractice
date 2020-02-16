#include<iostream>
#include<algorithm>
using namespace std;
 
const int MAX = 100000 + 5;
 
int a[MAX];
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    /*int left = 0, right = n - 1;
    int app = 0, bpp = 0;
    bool appb = true;
    while (left <= right) {
        int m;
        bool p;
        if (a[left] < a[right]) {
            m = a[right];
            p = true;
        }
        else {
            m = a[left];
            p = false;
        }
        if (appb) {
            app += m;
            appb = false;
        }
        else {
            bpp += m;
            appb = true;
        }
        if (p)
            right--;
        else
            left++;
    }
    if (app >= bpp) {
        cout << "Applese" << endl;
    }
    else  cout << "Bpplese" << endl;*/
 
    cout << "Applese" << endl;
 
 
    return 0;
}
