#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
const int MAX = 1000000 +5;

int a[MAX];


int main(){
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    ll sum = 0;
    for (int i = 0; a[i] * 2 < s; i++){
        if(binary_search(a + i, a + n, s - a[i])){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
