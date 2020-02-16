#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],b[N];
ll phi[N];
ll sum,cnt;
bool cmp(int a,int b){
    return a>b;
}

void findprime(){   //找出来素因子
    cnt=0;
    for(ll i=2;i<=sqrt(sum);i++){
        if(sum%i==0)
            phi[cnt++]=i;
        while(sum%i==0)
            sum/=i;
    }
    phi[cnt++]=sum;   //找出来的素因子存在这个数组里
}

int main(){
    int t,n;
    ll h,num,ret,minn;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        sum=0;
      for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
      }
    findprime();
    minn=1e10+10;
    for(int j=0;j<cnt;j++){   //跑一遍所有的素因子，本来素因子就很少，不会超时
        num=0;
        for(int i=0;i<n;i++)
            b[i]=a[i];
        for(int i=0;i<n;i++){
            b[i]=b[i]%phi[j]; //取余操作
            num+=b[i];
        }
        ret=0;
        sort(b,b+n,cmp);
        int i=0;
        while(num>0&&i<n){
            ret+=phi[j]-b[i];//将补的次数(移动次数)加到ret中
            num-=phi[j];//总数减去
            i++;
        }
        minn=min(minn,ret);//找出移动次数最小的
    }
    printf("%lld\n",minn);
    }
    return 0;
}
