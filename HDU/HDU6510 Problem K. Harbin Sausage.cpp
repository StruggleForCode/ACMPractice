#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int h, r;
    cin >> h >> r;
    ll sum = r * r * h * 3 + 4 * r * r * r;
    cout << sum;
    return 0;
}
