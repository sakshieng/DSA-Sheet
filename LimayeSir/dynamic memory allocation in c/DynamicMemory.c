#include <stdio.h>
#include <stdlib.h>

typedef struct result
{
    int rno;
    double mrk;
}RES;

typedef struct marks
{
    int rno;
    int nos;
    int *ptr;
}MRK;

//function to update MRK 

void input(MRK *a)
{
    int i=0;
    printf("\nRoll No. :");
    scanf("%d",&a->rno);
    printf("\nSubject Count :");
    scanf("%d",&a->nos);
    a->ptr=(int *)malloc(a->nos *sizeof(int));
    printf("\nEnter Marks :\n"); 
    for(i=0;i<a->nos;i++)
        scanf("%d",(a->ptr+i));   
}

//function to display marks

void display(MRK *a)
{
    int i=0,tot=0;
    printf("\nRoll No. :%d",a->rno);
    printf("\nMarks\n");
    for( ;i<a->nos;i++)
    {
        printf("%4d",*(a->ptr+i));
        tot+=*(a->ptr+i);
    }
    printf("\nTotal :%d",tot);
    return;
}

int total(MRK *a)
{
    int i=0,tot=0;
    while(i<a->nos)
    {
        tot+=*(a->ptr+i);
        i++;
    }
    return tot;
}

void displayRES(RES *b)
{
    printf("\nResult\n");
    printf("Roll No. :%d\nMarks :%lf",b->rno,b->mrk);
}

void convert(MRK *a,RES *b)
{
    b->rno=a->rno;
    b->mrk=(double)total(a)/a->nos;
}

void main()
{
    MRK a;
    RES b;
    input (&a);
    display(&a);
    convert(&a,&b);
    displayRES(&b);
    free(a.ptr);
    return;
}