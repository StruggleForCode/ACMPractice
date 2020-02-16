#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
 
const int MAX = 100 + 5;
 
int dp[MAX][MAX];
 
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            int flag = 0;
            if (s1[i - 1] == s2[j - 1])
                flag = 0;
            else flag = 1;
            dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + flag));
        }
    }
 
    /*if (fabs(s1.size() - dp[s1.size()][s2.size()]) <= 2)
    cout << "YES" << endl;
    else cout << "NO" << endl;*/
    if (dp[s1.size()][s2.size()] <= 2)
        cout << "YES" << endl;
    else cout << "NO" << endl;
 
    return 0;
}
