#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,x,y;
	    int i;
	    int a=0,b=0;
	    scanf("%d%d%d",&n,&x,&y);
	    char s[n];
	    scanf("%s",s);
	    for(i=0;i<n;i++)
	    {
	        if(s[i]=='0' || s[i+1]=='1')
	        a++;
	        if(s[i]=='1' || s[i+1]=='0')
	        b++;
	    break;
        i++;
	    }
	    if(s[i]!='\0')
	    printf("%d\n",(x*a+b*y));
	    else
	    printf("0\n");
        
	}
}