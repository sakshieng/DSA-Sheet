#include<stdio.h>
int main()
{
    int total=80000,lm,ilm,lw,ilw,m,w;
    m=52*80000/100;
    w=48*80000/100;

    lm=35*80000/100;
    ilm=m-lm;

    lw=13*80000/100;
    ilw=w-lw;

    printf("illeterate men:%d\n",ilm);
    printf("illeterate women:%d\n",ilw);
    return 0;
    
}
