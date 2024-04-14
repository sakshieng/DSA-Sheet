#include <stdio.h>
int main()
{
    int a, b, res, flg = 0;
    char opr;
    do
    {
        if (flg == 0)
        {

            printf("\nA:");
            scanf("%d", &a);
            flg = 1;
        }
        else
        {
            a = res;
            printf("\nOperators \n+:add \n-:sub \n*:mult \n/:div \nChoose Operators\n");
            scanf("%c", &opr);
            if (opr == '=')
            {
                if (flg == 1)
                {
                    printf("\nOutput:%d", res);
                    break;
                }
            }
            printf("\nB:");
            scanf("%d", &b);
            switch (opr)
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '/':
                res = a / b;
                break;
            case '*':
                res = a * b;
                break;
            }
        }
    }while (1);
    return 0;
}