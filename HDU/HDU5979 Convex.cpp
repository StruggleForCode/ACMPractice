#include <iostream>
 #include <algorithm>
 #include <cmath>
 using namespace std;
 
 const double PI = 3.1415926;
 
 
 int main(){
     int n, dis;
     while(cin >> n >> dis){ 
         int angle;
         double area = 0;
         for(int i = 0; i < n; i++){
             cin >> angle;
             double t = 2 * PI * angle/(360 * 1.0);
             area += 0.5 * dis * dis * sin(t);
        }
        //double t = 2 * PI * angle/(360 * 1.0);
        printf("%.3lf\n", area);
     }
     return 0;
 }
