#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdio> 
using namespace std;

inline int read(){
	int X = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){ w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)){ X = (X << 3) + (X << 1) + (ch ^ 48); ch = getchar();}
	return w ? -X : X;
}

inline int write(int x){
	if(x < 0) putchar('-');
	if(x > 9) write(x/10);
	putchar(x % 10 + '0');
}

inline double dread(){
	double X = 0, Y = 1.0; char ch = 0;
	int w = 0;
	while(!isdigit(ch)) w |= ch == '-', ch = getchar();
	while(isdigit(ch)) X = X * 10 + (ch ^ 48), ch = getchar();
	ch = getchar();
	while(isdigit(ch)) X += (Y /= 10) * (ch ^ 48), ch = getchar();
	return w ? -X:X;
}


int main(){
	
	int x = read();
	write(x);
	
	double y = dread();
	printf("%.6lf", y);
	
	return 0;
}
