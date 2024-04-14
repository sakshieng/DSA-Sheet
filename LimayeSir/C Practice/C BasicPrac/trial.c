#include <stdio.h>

int main(void) {
	// your code goes here
	int t,x,y,d;
	scanf("%d",&t);
	while(t--)
	{
	    int p;
	    scanf("%d%d%d",&x,&y,&d);
	    p=x-y;
	    if(d>=p)
	    printf("\nYES");
	    else
	    printf("\nNO");
	}
	return 0;
}
