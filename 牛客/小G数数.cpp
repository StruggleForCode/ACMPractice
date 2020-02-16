#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
const int MAX = 500 + 5;
 
int a[MAX];
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] >= a[j])
                continue;
            for (int k = j + 1; k < n; k++) {
                if (a[k] >= a[j])
                    continue;
                for (int l = k + 1; l < n; l++) {
                    if (a[i] < a[k] && a[k] < a[j] && a[j] < a[l])
                        sum++;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
