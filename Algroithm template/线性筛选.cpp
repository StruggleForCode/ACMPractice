#include <iostream>
#define MAX 10000000
using namespace std;
int prime[MAX];			//用于储存素数
bool flag[MAX];			//判断某一个数是否为素数

int main() {
	int cnt = 0;
	int n;
	cin >> n;
	flag[0] = true;
	flag[1] = true;
	for (int i = 2; i < n; i++) {
		if (!flag[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt; j++) {
			if (i * prime[j] > n)
				break;
			flag[i*prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
	for (int i = 0; i < n; i++)
		if (!flag[i])
			cout << i << ' ';


	return 0;
}
