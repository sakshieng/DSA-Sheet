#include<stdio.h>
int main()
{
	int i,j,n1,n2;
	printf("Enter value of n1 and n2 : ");
	scanf("%d %d",&n1,&n2);
    //here the range is declared in between n
	for(j = n1+1; j <= n2-1; j++)
	{
		for(i=2;i<j;i++)
		  if (j%i==0)
		    break;
		if (j==i)
		printf("%d ",j);
	}
	return 0;
}