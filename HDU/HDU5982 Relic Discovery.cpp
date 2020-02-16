#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long int sum = 0;
        cin >> n;
        while(n--){
            int a, b;
            cin >> a >> b;
            sum += a * b; 
        }
        cout << sum << endl;
    }
    return 0;
}
