#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
	    int i;
	    scanf("%d",&n);
	    char s[n];
	    scanf("%s",s);
	    int cnt=0;
	    for(i=0;i<n;i++)
	    {
	    if(s[i]==1)
	    cnt++;
	    else
	    {
	    if(s[i]==1 && s[i+1]==1)
	    printf("%d\n",cnt+1);
	    else
	    printf("%d\n",cnt);
	    }
	    }
	}
	return 0;
}

