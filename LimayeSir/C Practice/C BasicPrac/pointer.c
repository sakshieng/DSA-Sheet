#include<stdio.h>
void main( )
{
	int num[5] = { 10,20,30,40,50 };
	int *ptr, i;
	ptr = num;
	for ( i = 0 ; i < 5 ; i ++ )
		{
                 printf ("%d\n",*ptr); //or can be used *ptr++
		        ptr++;
		}
	return;
}
