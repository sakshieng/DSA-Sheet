#include<stdio.h>
int main()
{
    int a,b,res,flg=1;
    char opr;
    system("cls");
    printf("Enter 2 Operands");
    scanf("%d %d",&a,&b);
    printf("\nOperators \n+:add \n-:sub \n*:mul \n/:div \nchoose operator\n");
    scanf(" %c",&opr);
    switch(opr)
    {
        case '+':
        res=a+b;
        break;

        case '-':
        res=a-b;
        break;

        case '*':
        res=a*b;
        break;

        case '/':
        res=a/b;
        break;

        default:
        flg=0;
    }
    if(flg==0)
    printf("\nInvalid Input");
    else
    printf("\nResult:%d",res);
    return 0;
}