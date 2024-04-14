#include<stdio.h>
#include<conio.h>
struct student
{
    int rollnumber,marks;
    char name[30];
    //char branch[30];
};
int main()
{
    int i,n=5;
    struct student s[5];
    printf("enter student detail");
    while(n>0)
    {
        i=0;
        scanf("%d%d%s",&s[i].rollnumber,&s[i].marks,&s[i].name);
        i++;
        n--;
    }
    n=5;
    i=0;
    while(n>0)
    {
    printf("roll number is %d\n",s[i].rollnumber);
    printf("marks is %d\n",s[i].marks);
    puts(s[i].name);
    i++;
    n--;
    }
    getch();

}