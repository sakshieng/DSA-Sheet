#include<stdio.h>
int main()
{
	int i, j, num1, num2;
	printf("Enter value of num1 and num2 : ");
	scanf("%d %d",&num1,&num2);
	for(j = num1+1; j <= num2-1; j++)
	{
		for(i=2;i<j;i++)
		  if (j%i==0)
		    break;
		if (j==i)
		printf("%d ",j);
	}
	return 0;
}