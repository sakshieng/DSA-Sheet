#include <stdio.h>

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--)
    {
    long long int n;
	// your code goes 
	int cnt=0;
	int i=0;
	scanf("%lld",&n);
	char s[n];
	gets(s);
	for(;i<n;i++)
	{
	    if(s[i]=='5' || s[i]=='0')
    {
	        cnt=1;
    }
	   
	}
	 if(cnt==1)
     printf("\nYes");
	 else
	 printf("\nNo");
	
    }
	
	return 0;
}

