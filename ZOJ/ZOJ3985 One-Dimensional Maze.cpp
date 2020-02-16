#include <iostream>
#include <string>

using namespace std;

int t;

int main()
{
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;
        s = " " + s;

        int cnt = 0, ans = 0;
        for (int i = 2; i < m; i++){
            if(s[i] != 'L') ans++;
        }
        for (int i = m + 1; i < n; i++){
            if(s[i] != 'R') cnt++;
        }

        if(s[m] == 'L')
            cnt++;
        else
            ans++;

        cout << min(ans,cnt) << endl;

    }
    return 0;
}

