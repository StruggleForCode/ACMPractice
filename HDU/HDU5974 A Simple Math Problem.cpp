#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        int g = gcd(a, b);
        //cout << g << endl;
        int deait = a * a - 4 * g * b;
        if(deait < 0){
            printf("No Solution\n");
            continue;
        }
        int q = (int)sqrt(deait);
        if(deait != q * q){
            printf("No Solution\n");
            continue;
        }
        int x1 = (a - q) / 2;
        int x2 = (a + q) / 2;
        int x = min(x1, x2);
        printf("%d %d\n",x, a - x);
        
    }
    return 0;
} 
