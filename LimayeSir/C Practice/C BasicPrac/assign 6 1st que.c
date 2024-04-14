#include <stdio.h>
int main() 
{
    //use of nested if conditional for min and max of 3 inputed no
    int a,b,c;
    printf("\nEnter three numbers");
    scanf("%d %d %d",&a,&b,&c);
    printf("\nmax is %d",((a>b)?((a>c)?a:c):((b>c)?b:c)));

    printf("\nmin is %d",((a<b)?((a<c)?a:c):((b<c)?b:c)));
    return 0;

}
