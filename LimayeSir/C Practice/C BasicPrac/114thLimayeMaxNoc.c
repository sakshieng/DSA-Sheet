#include <stdio.h>
int main() 
{
    int no,dig,tmp,i,k=0;
    printf("\nEnter No.");
    scanf("%d",&no);
    for(i=9;i>=0;i--)
    {
        tmp=no;
        while(tmp>0)
        {
            dig=tmp%10;
            if(dig==i)
            k=k*10+i;
            tmp/=10;
        }
    }
    printf("\nOutput:%d",k);
    return 0;  
}