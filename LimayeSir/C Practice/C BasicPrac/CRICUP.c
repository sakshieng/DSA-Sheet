#include<stdio.h>
int main(void)
{
    int T,X,Y,D;
	scanf("%d",&T);
	while(T--)
	{
	    int p,m;
	    scanf("%d%d",&X,&Y);
	    if(X>Y)
	    {
	    p=X-Y;
	    if(D>=p)
	    printf("\nYES");
	    else
	    printf("\nNO");
	    }
	    else
	    {
	        m=Y-X;
	        if(D>=m)
	        printf("\nYES");
	        else
	        printf("\nNO");
	    }
	}
	return 0;
}


