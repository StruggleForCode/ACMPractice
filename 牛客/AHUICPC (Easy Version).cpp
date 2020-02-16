#include <iostream>
#include <string>
using namespace std;
 
 
int main(){
    int n;
    cin >> n;
    string s = "AHUICPC";
    if(n <= 8){
        for (int i = 1; i < n; i++){
            cout << 'A';
        }
        cout << s << endl;
    }else if(n == 9){
        cout << "AAAHHHUICPC" << endl;
    }else if(n == 10){
        cout << "AAHHHHHUICPC" << endl;
    }
    return 0;
}
