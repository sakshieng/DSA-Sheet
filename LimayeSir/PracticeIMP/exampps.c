#include<stdio.h>
int main()
{
    int x[5]={5,2,3,4,1};
    int* ptr;
    ptr=&x[2];
    printf("*ptr=%d\n",*ptr);
    printf("*(ptr+1)=%d\n",*(ptr+1));
    printf("*(ptr-1)=%d",*(ptr-1));    
}