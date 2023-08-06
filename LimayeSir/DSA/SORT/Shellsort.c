#include<stdio.h>
#include<stdlib.h>
#define M 10
// distinct pos che element sort honar
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
void input(int *a)
{
    int i=0;
    while (i < M)
    {
        printf("\nEnter no:");
        scanf("%d",a+i);
        i++;
    }
}
void display(int *a,int flg)
{
    int i=0;
    if(flg == 0)
    {
        printf("\nBefore sorting\n");
    }
    else
    {
        printf("\nAfter sorting\n");
    }
    for( i = 0; i < M; i++)
    {
        printf("%4d",a[i]);
    }
}
void shell(int *a)
{
    int i,h,w,curr;
    i=(M-1)/2;
    // now shell size becomes 10-1/2=9/2=4
    while (i > 0)
    {
        for(curr=i;curr<M;curr++)
        {
            // 0 4 mdhe 1 5 mdhe compare
            h=a[curr];
            w=curr-i;
            while (w>=0 && h < a[w])
            {
                a[w+i] = a[w];
                w=w-i;
            }
            a[w+i]=h;
        }
        i/=2;
    }
}
int main()
{
    int x[M];
    input(x);
    display(x,0);
    shell(x);
    display(x,1);
}