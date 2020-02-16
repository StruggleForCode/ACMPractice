#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAX = 100000 + 5;
 
 
struct Node {
    int a;
    int b;
    long long int sum;
};
 
Node node[MAX];
 
bool cmp(Node x, Node y) {
    return (x.b * 1.0 / x.a) > (y.b * 1.0 / y.a);
}
 
 
int main() {
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> node[i].a >> node[i].b;
    }
    sort(node, node + n, cmp);
    node[n - 1].sum = node[n - 1].b;
    for (int i = n - 2; i >= 0; i--) {
        node[i].sum += node[i + 1].sum + node[i].b;
    }
    long long int cnt = 0;
    for (int i = 1; i < n; i++) {
        cnt += node[i - 1].a * node[i].sum;
    }
    cout << cnt << endl;
 
    return 0;
}
 
 
/*
6
100001 1
4 5
4 3
6 2
100000 10
2 6
*/
