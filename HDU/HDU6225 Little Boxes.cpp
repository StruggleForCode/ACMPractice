#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int num1[10000];
int num2[10000];
int num3[10000];
int num4[10000];

void add(string s1, string s2, string s3, string s4){
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    memset(num3, 0, sizeof(num2));
    memset(num4, 0, sizeof(num2));
    for (int len = 0, i = s1.size() - 1; i >= 0; i--){
        num1[len++] = s1[i] - '0';
    }
    for (int len = 0, i = s2.size() - 1; i >= 0; i--){
        num2[len++] = s2[i] - '0';
    }
    for (int len = 0, i = s3.size() - 1; i >= 0; i--){
        num3[len++] = s3[i] - '0';
    }
    for (int len = 0, i = s4.size() - 1; i >= 0; i--){
        num4[len++] = s4[i] - '0';
    }
//    for (int i = 5; i >= 0; i--){
//        cout << num1[i];
//    }
//    cout << endl;
//    
//    for (int i = 5; i >= 0; i--){
//        cout << num2[i];
//    }
//    cout << endl;
//    
//    for (int i = 5; i >= 0; i--){
//        cout << num3[i];
//    }
//    cout << endl;
//    
//    for (int i = 5; i >= 0; i--){
//        cout << num4[i];
//    }
//    cout << endl;
    
    for (int i = 0; i < 10000; i++){
        num4[i] += num3[i] + num2[i] + num1[i];
        if(num4[i] >= 10){
            num4[i + 1] += num4[i] / 10;
            num4[i] %= 10;
        } 
    }
    int i;
    for(i = 10000; i > 0 && num4[i] == 0; i--);
    for (; i >= 0; i--){
        cout << num4[i];
    }
    cout << endl;
     
}


int main(){
    int  t;
    cin >> t;
    while(t--){
        string s1, s2, s3, s4;
        cin >> s1;
        cin >> s2;
        cin >> s3;
        cin >> s4;
        add(s1, s2, s3, s4);        
    }
    return 0;
}
