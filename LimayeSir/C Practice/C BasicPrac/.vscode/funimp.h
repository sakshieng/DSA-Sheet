#include<stdio.h>
void main()
{
{
    int no,res,opt;
    while(1);
}
printf("\nMenu \n1.Enter no \n2.Prime no \n3.Odd even \nFibo \n5.Digitsum \n6.Reverse \n7.Palindrome \n8.Exit \n.Option");
scanf("%d",&opt);
if(opt>7)
break;
switch(opt);
{
    {
        case 1:
            printf("\nEnter the number:");
            scanf("%d", &no);
            break;
        case 2:
            if (prime(no) == 0)
                printf("\nNot");
            printf("Prime");
            break;
        case 3:
            if (oddeven(no) == 1)
                printf("\nodd");
            else
                printf("\nEven");
            break;
        case 4:
            printf("\nFibo element :%d", fibo(no));
            break;
        case 5:
            printf("\nDigit sum :%d", digitsum(no));
            break;
        case 6:
            printf("\nReverse number:%d", rev(no));
            break;
        case 7:
            res = rev(no);
            if (res != no)
                printf("\nNOT");
            printf("Palindrome");
            break;
  }
    printf("\nProgram is completed successfully....");
    return;
}
}
