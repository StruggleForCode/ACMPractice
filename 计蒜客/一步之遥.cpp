#include<stdio.h>
int main()
{
    int x,y,t,flag=0;
    for(t=0; ;t++)    //������Ҫt����� 
    {
        for(x=0;x<t;x++)    //��x��97 
        {
            y=t-x;    //ʣ����y��127 
            if(97*x-127*y==1)
            {
                printf("%d",x+y);
                flag=1;
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            break;
    }    
    return 0;
}
