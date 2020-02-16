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

void findprime(){   //�ҳ���������
    cnt=0;
    for(ll i=2;i<=sqrt(sum);i++){
        if(sum%i==0)
            phi[cnt++]=i;
        while(sum%i==0)
            sum/=i;
    }
    phi[cnt++]=sum;   //�ҳ����������Ӵ������������
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
    for(int j=0;j<cnt;j++){   //��һ�����е������ӣ����������Ӿͺ��٣����ᳬʱ
        num=0;
        for(int i=0;i<n;i++)
            b[i]=a[i];
        for(int i=0;i<n;i++){
            b[i]=b[i]%phi[j]; //ȡ�����
            num+=b[i];
        }
        ret=0;
        sort(b,b+n,cmp);
        int i=0;
        while(num>0&&i<n){
            ret+=phi[j]-b[i];//�����Ĵ���(�ƶ�����)�ӵ�ret��
            num-=phi[j];//������ȥ
            i++;
        }
        minn=min(minn,ret);//�ҳ��ƶ�������С��
    }
    printf("%lld\n",minn);
    }
    return 0;
}
