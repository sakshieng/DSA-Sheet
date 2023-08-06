
#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    long long int n;
	    scanf("%lld",&n);
	    if(n%4==3 || n%4==2)
	    printf("3\n");
	    else
	    if(n%4==0)
	    printf("%d\n",n+3);
	    else
	    if(n%4==1)
	    printf("%d\n",n);
	  
	}
	return 0;
}

