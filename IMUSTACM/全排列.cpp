
#include <iostream>
#include <vector>
using namespace std;

int n, step, a[10], book[10];


void dfs(int step) {
	if (step == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (book[i] == 0) {
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
}


int main()
{
	/*for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3; k++) {
				if (j != i && k != i && k != j)
					cout << i << j << k << endl;
			}
		}*/

	cin >> n;
	dfs(1);
	return 0;
}