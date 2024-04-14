#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,sum,r,term;
	printf("Enter the first term of the G.P. : ");
	scanf("%d",&a);
	printf("Enter the number of terms in the G.P. : ");
	scanf("%d",&n);
	printf("Enter the common ratio of the G.P. : ");
	scanf("%d",&r);
	printf("\nThe G.P is : ");
	for (int i = 0; i < n; i++)
	{
		term = a * pow(r,i);
		printf("%d ",term);
	}
	if (r!=1)
	{
		sum = a * (1 - pow(r,n)) / (1 - r);
	    printf("\nThe sum of the G.P. = %d\n",sum);
	}
	else 
		printf("\nThe sum of the G.P. = %d\n",a * n);
	return 0;
}