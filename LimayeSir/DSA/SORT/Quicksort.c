#include<stdio.h>
#include<stdlib.h>
#define M 10
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
void swap(int *p,int *q)
{
    int r=*p;
    *p=*q;
    *q=r;
}
void pivot(int *a,int l,int r)
{
    if(a[l] > a[r])
        swap(a+l,a+r);
}
// we have used do while here as at least one time the loop gets exexuted for l<r
int partition(int *a,int l,int r)//pivot chi pos return krte
{
    int i=l,j=r,k;
    pivot(a,l,r);
    k=a[l];//assign leftmost element to k
    do
    {
        do
        {
            ++i;
        } while (a[i] < k);
        do
        {
            j--;
        } while (a[j] > k);
        if (i < j)
        {
            swap(a+i,a+j);
        }
    } while (i < j);
        return j;
}
// main mdhun phila quick call krnar then 3 partition mdhe divide honar as 2da quick call houn
void quick(int *a,int l,int r)
{
    // left part mdhe left ani right la quick call houn ani mg main chya right la quick call houn execute
    int k;
    if(l < r)
    {
        k=partition(a,l,r);
        quick(a,l,k-1);
        quick(a,k+1,r);
    }
}
int main()
{
   int x[M];
   input(x);
   display(x,0);
   quick(x,0,M-1); 
   display(x,1);
   return 0;
}