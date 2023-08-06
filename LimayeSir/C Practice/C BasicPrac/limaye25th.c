#include <stdio.h>
int main()
{
    int no;
    printf("enter a no\n");
    scanf("%d",&no);
    printf("\nNo:%d is %s",no,((no>0)?"positive no":((no<0)?"negative no":"0")));
    return 0;
}