#include <iostream>
#include <cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include <cstring>
#include <stack>
#define fori(l,r) for( int i = l ; i <= r ; i++ )
#define forj(l,r) for( int j = l ; j <= r ; j++ )
#define fork(l,r) for( int k = l ; k <= r ; k++ )
#define lef rt<<1
#define rig rt<<1|1
#define mid (l+r)>>1
#define mem(a,val) memset(a,val,sizeof a)
typedef long long ll;
using namespace std;
int r,c;
const int maxn = 1<<12;
ll dp[13][maxn];
bool initcheck( int x )     //检查第一行的状态
{
    int cnt = c-1;
    fori(1,c)
    {
        int curdigit = ( x>>cnt )&1;
        if( curdigit == 0 )
        {
            if( i == c || ( ( x>>(cnt-1) )&1 ) == 1 )
                return false;
            i++;
            cnt--;
        }
        cnt--;
    }
    return true;
}
bool judge( int cur,int pre )
{
    int cnt = c-1;
    fori(1,c)
    {
        if( ( cur>>cnt )&1 )   //当前行某一位为 1
        {
            if( ( pre>>cnt )&1 )
                return false;
        }
        else
        {
            if( !( ( pre>>cnt)&1 ) )   //前面一行不影响，那么当前行要横着铺
            {
                if( i == c || ( pre>>(cnt-1)&1 ) || ( cur>>(cnt-1) )&1 )
                    return false;
                i++;        //横着铺有两格，下一个不用判断
                cnt--;
            }
        }
        cnt--;
    }
    return true;
}
int main()
{
    while( scanf("%d %d",&r,&c) == 2 && r )
    {
        if( c > r )
            swap(c,r);
        mem(dp,0);
        int right = 1<<c;
        fori(0,right-1)
            if( initcheck(i) )
                dp[1][i] = 1;
        fori(2,r)
        {
            forj(0,right-1) //枚举当前行的状态
                fork(0,right-1) //枚举上一行的状态
                    if( judge(j,k) )
                        dp[i][j] += dp[i-1][k];
        }
        printf("%lld\n",dp[r][0]);
    }
	return 0;
 
}
 
/*
2 3
1 0 1
0 1 0
*/
