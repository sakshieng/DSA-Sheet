#include <stdio.h>
//string input krke 5 or 0 check then divisible

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int d;
	    scanf("%d",&d);
	    int count=0;
	    int i=0;
	    char n[d];
	    scanf("%s",n);
	    for(i=0;i<d;i++)
	    {
	        if(n[i]=='0' || n[i]=='5')
	        
	        count=count+1;
	    }
	    if(count==0)
	    printf("NO\n");
	    else
	    printf("YES\n");
	}
	return 0;
}

