//2]Write a program in C to read an existing file. 
#include <stdio.h>
#include <stdlib.h>
#define N 20
void main()
{
	FILE *fptr;
	char fname[N];
	char str;
    system("cls");
    printf("\n\n Read an existing file :\n");
	printf(" Input the filename to be opened : ");
    scanf("%s",fname);
	fptr = fopen (fname, "r");  
	if (fptr == NULL)
	{
		printf(" File does not exist or cannot be opened.\n");
		exit(0);
	}
	printf("\n The content of the file %s is  :\n",fname);
	str = fgetc(fptr);
	while (str != EOF)
		{
			printf ("%c", str);
			str = fgetc(fptr);
		}
	fclose(fptr);
    printf("\n\n");
}