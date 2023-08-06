#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct books
{
	char t[20],n[20],s[20];
	int b,i;
};
void book(struct books st);

void main()
{
    system("cls");
	struct books st;
	system("cls");
	printf("Enter the Book Title:");
	scanf("%s",&st.t);
	printf("Enter the Book Name:");
	scanf("%s",&st.n);
    printf("Enter the Book Subject:\n");
	scanf("%s",&st.s);
}
void book(struct books st)
{
	printf(" \n Book Title is =%s \n",st.t);
	printf("Book Name is =%s \n",st.n);
	printf("Book Subject is =%s \n",st.s);
}
