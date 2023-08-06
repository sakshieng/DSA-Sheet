#include<stdio.h>
int isinter(long int a)
{
    int sum=0,pro=1,dig,res;
    for (;a>0;a/=10)
    {
        dig=a%10;
        sum+=dig;
        pro*=dig;
    }
    res=pro%sum;
    if (res==0)
        return 1;
    else 
    return 0;
}

void main()
{
    int T,tmp,cnt;
    long int A,B,no;
    scanf("%d",&T);
    while (T--)
    {   cnt=0;
        scanf("%ld %ld",&A,&B);
        
        for (no=A;no<=B;)
        {   
            tmp=isinter(no);
            if (tmp==1)
                cnt++;
            no++;
        }
        printf("%d\n",cnt);
    }
    return;
}