#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;


typedef long long ll;

const int maxn = 200000 + 100;

ll a[maxn];
ll b[maxn];
ll sum;

int main(){
    ll k, m, n, p;
    while(~scanf("%lld%lld%lld%lld", &k, &m, &n, &p)){
        for (int i = 0; i < k; i++){
            scanf("%lld", &a[i]);
        }
        sum = 0;
        sort(a, a + k); 
        memset(b, 0, sizeof(b));
        ll t = n, cnt = 0;
        for (int i = 2; i <= m; i++){
            b[i] = (b[i - 1] * n) % p;
            for (int j = 0; j < t; j++){
                b[i] = (b[i] + a[cnt++]) % p;
            }
            t *= n;
        }
        for (int i = 2; i <= m; i++){
            //cout << b[i] << endl;
            sum = (sum + b[i]) % p;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
