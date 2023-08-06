#include <stdio.h>
int main()
{
    int i=1,x,Min=0,Max=0;
    while(i<=10)
    {
        printf("\nN0.");
        scanf("%d",&x);
        if(i==1)
        Max= Min=x;
        else
        {
            Max= Min=x;
            if(x>=Max)
            Max=x;
            else
            {
                if(x<=Min)
            Min=x;
            }
        i++;
        }
    }
   printf("\nMax:%d",Max);
   printf("\nMin:%d",Min);    
    return 0;
}