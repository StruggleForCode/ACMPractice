#include <iostream>
using namespace std;
const int maxn = 110;
int a[maxn], d[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        d[i] = a[i] - a[i - 1];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r, v;
        cin >> l >> r >> v;
        d[l] += v;
        d[r + 1] -= v;
    }
    
    for (int i = 1; i <= n; i++){
        a[i] = a[i - 1] + d[i];
        cout << a[i] << " ";
    }
    
    return 0;  
}


/*
5
1 2 3 4 5
3
1 5 1
2 4 3
5 5 2 
*/ 
