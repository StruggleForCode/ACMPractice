#include <iostream>
#include <math.h>
using namespace std;
 
 
int main() {
    int l1, l2;
    cin >> l1 >> l2;
    int t;
    cin >> t;
    while (t--) {
        double x, y;
        cin >> x >> y;
        double len = sqrt(x * x + y * y);
        //cout << len << endl;
        if ((len > fabs(l2 - l1) && len < l2 + l1) || fabs(len - l1) < 1e-6 || fabs(len - l1 - l2) < 1e-6) {
            cout << "0.00000000" << endl;
        }
        else {
            //cout << "Hell" << endl;
            if (len < fabs(l1 - l2)) {
                printf("%.8lf\n", fabs(l1 - l2) - len);
            }
            else {
                printf("%.8lf\n", len - l1 - l2);
            }
        }
    }
    return 0;
}
