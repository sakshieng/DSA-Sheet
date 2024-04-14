#include <stdio.h>
// to compute digit sum of 3 digit inputed number
int main()
{
    int no, dig, tot = 0, df = 100;
    // df=division factor
    printf("\nenter 3digit no");
    scanf("%d", &no);
    dig = no / df;
    tot += dig;
    no = no % df;
    df /= 10;
    dig = no / df;
    tot += dig;
    no = no % df;
    df /= 10;
    dig = no / df;
    tot += dig;
    no = no % df;
    df /= 10;
    printf("\ndigits sum :%d", tot);
    return 0;
}