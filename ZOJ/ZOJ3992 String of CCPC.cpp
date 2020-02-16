#include <iostream>

using namespace std;

int t;

int main()
{
    cin >> t;
    while(t--)
    {
        string s;
        int n;

        cin >> n;
        cin >> s;

        int ans  = 0;
        for(int i = 0;i <= n-4;i++)
        {
            string subb = s.substr(i,5);
            if(subb == "CCCPC"){
                ans++;
                i = i+ 3;
            }
            string sub = s.substr(i,4);

            if(sub == "CCPC")
            {
                ans++;
            }

        }

       // cout << ans << endl;
        s =" " + s;


        for(int i = 1;i <= n-2;i++)
        {
            string sub = s.substr(i,3);



            if(sub == "CCC" && s[i+3] != 'P')
            {
                ans++;
                break;
            }

            if(sub == "CCP" && s[i+3] != 'C')
            {
                ans++;
                break;
            }

            if(sub == "CPC" && s[i-1] != 'C')
            {
                ans++;
                break;
            }
        }
        cout <<ans <<endl;
    }
    return 0;
}

