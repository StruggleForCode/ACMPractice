#include <iostream> 
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

ll sum[maxn];
ll mul[maxn];

void init(){
    sum[1] = 0;
    mul[1] = 1;
    for (int i = 2; i <= maxn; i++){
        sum[i] = sum[i - 1] + i;
        mul[i] = mul[i - 1] * i % mod;
    }
}

ll quick_pow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1){
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int inv(int a){
    return quick_pow(a, mod - 2) % mod; 
}

int binary_search(int x){
    int l = 1, r = maxn;
    int p;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(sum[mid] <= x){
            p = mid;
            l = mid + 1;
        } 
        else if(sum[mid] > x) r = mid - 1;
    }
    return p;
}

int main(){
    init();
    int t;
    scanf("%d", &t);
    while(t--){
        ll x;
        scanf("%lld", &x);
        if(x == 1){
            printf("1\n");
            continue;
        }
        int k = binary_search(x);
        int num = x - sum[k];
        //cout << k << endl;
        ll ans = 0;
        if(num == k){
            ans = (mul[k] * inv(2) % mod * (k + 2))% mod;
        }
        else {
            ans = (mul[k + 1] * inv(mul[k + 1 - num]) % mod * mul[k - num]) % mod;
        }
        printf("%lld\n", ans);
    }
    
    return 0;
} 
