#include <iostream>
#include <algorithm>
using namespace std;
 
const int MAX = 100000 + 5;
 
struct Test {
    int time;
    int strat;
};
 
 
Test test[MAX];
 
bool cmp(Test a, Test b) {
    return a.strat < b.strat;
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        test[i].time = u;
    }
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        test[i].strat= u;
    }
    sort(test, test + n, cmp);
 
    int leisure = test[0].strat -  test[0].time;
     
    bool success = true;
    for (int i = 1; i < n; i++) {
        if (leisure < 0) {
            success = false;
            break;
        }
        leisure += test[i].strat - test[i - 1].strat - 2;
        leisure -= test[i].time;
    }
 
    if (success)
        cout << "YES" << endl;
    else cout << "NO" << endl;
 
    return 0;
}
