#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
const int MAX = 100000 + 5;
 
int father[MAX];
int a[MAX];
int b[MAX];
ll c[MAX];
 
bool cmp(ll a, ll b) {
    return a > b;
}
 
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}
 
void merge(int u, int v) {
    father[find(u)] = find(v);
}
 
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i <= n; i++) {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        merge(i, b[i]);
    }
    for (int i = 1; i <= n; i++) {
        find(i);
        c[father[i]] += a[i];
    }
    sort(c, c + MAX, cmp);
    ll cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += c[i];
    }
    cout << cnt << endl;
    return 0;
}
