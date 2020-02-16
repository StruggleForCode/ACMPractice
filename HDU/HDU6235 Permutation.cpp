#include <iostream>
#include <algorithm>
using namespace std;



int a[100000 + 5];


int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 1;
        for (int i = 1; i <= n; i += 2){
            a[i] = cnt++;
        }
        for (int i = 2; i <= n; i += 2){
            a[i] = cnt++;
        }
        for (int i = 1; i < n; i++){
            cout << a[i] << " ";
        }
        cout << a[n] << endl;
    }
    
    
    
}
