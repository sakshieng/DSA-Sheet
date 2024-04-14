// create a header file STU.h 
typedef struct student
{
    int rno;
    char nm[15];
    int mrk;
}STU;
// func to input
void input(STU *t,int n)
{
    t->rno=n;
    printf("\nName:");
    scanf("%s",t->nm);
    printf("\nMarks:");
    scanf("%d",&t->mrk);
}
void display(STU *t)
{
    printf("\nStudents data:\nRoll no:%d\nName:%s\nmarks:%d",t->rno,t->nm,t->mrk);
}
