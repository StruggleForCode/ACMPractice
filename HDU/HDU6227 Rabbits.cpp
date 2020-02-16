#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[505];
        //memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int x = a[1] - a[0] - 1;
        int y = a[n - 1] - a[n - 2] -1;
        int ans = 0;
        for (int i = 2; i < n - 1; i++){
            //cout << a[i] << " ";
            ans += a[i] - a[i - 1] - 1;
        }
        //cout << x << " " << y << endl; 
        cout << max(x, y) + ans << endl;
    }
    return 0;
} 
