#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    int rno;
    char nm[15];
    int mrk;
}STU;

typedef struct node
{
    STU s;
    struct node *next;
}NODE;

void input(STU *a,int no)
{
    a->rno=no;
    fflush(stdin);
    printf("\nName :");
    scanf("%s",a->nm);
    printf("\nMarks :");
    scanf("%d",&a->mrk);
}

void display(STU *a)
{
    printf("\n%4d %-15s %4d",a->rno,a->nm,a->mrk);
}

typedef struct stulist
{
    NODE *st;
    int cnt;
}WLIST;

void init(WLIST *t)
{
    t->st=NULL;
    t->cnt=0;
}

//function to search numberwise

NODE *searchno(WLIST *t,int no)
{
    NODE *a=t->st;
    while(a!=NULL)
    {
        if(a->s.rno==no)
          break;
        a=a->next;  
    }
    return a;
}

//function to search name wise

NODE *searchnm(WLIST *t,char *b)
{
    NODE *a=t->st;
    while(a!=NULL)
    {
        if(strcmp(a->s.nm,b)==0)
          break;
        a=a->next;  
    }
    return a;
}


//function to add new record

void add(WLIST *t)
{
    int no;
    NODE *a;
    printf("\nRoll No. :");
    scanf("%d",&no);
    a=searchno(t,no);
    if(a!=NULL)
    {
        printf("\nRecord Exists");
        return; 
    }  
    a=(NODE *)malloc(sizeof(NODE));
    input(&a->s,no);
    a->next=t->st;
    t->st=a;
    t->cnt++;
}

//function to modify existing record 

void mod(WLIST *t)
{
    int no;
    NODE *a;
    printf("\nRoll No. :");
    scanf("%d",&no);
    a=searchno(t,no);
    if(a==NULL)
    {
        printf("\nRecord Does Not Exists");
        return; 
    }  
    input(&a->s,no);
}

//function to delete node

void del(WLIST *t)
{
    int no;
    NODE *a,*b,*c;
    printf("\nRoll No. :");
    scanf("%d",&no);
    a=searchno(t,no);
    if(a==NULL)
    {
        printf("\nRecord Does Not Exists");
        return; 
    }  
    if(a==t->st)
       t->st=a->next;
    else
    {
        b=t->st;
        while(b->next!=a)
           b=b->next;
        b->next=a->next;   
    }   
    free(a);
    t->cnt--;
}

//function to display all student data

void displayAll(WLIST *t)
{
    NODE *a=t->st;
    if(a==NULL)
      printf("\nEmpty List");
    else
    {
        while(a!=NULL)
        {
            display(&a->s);
            a=a->next;
        }
    }  
}

//function to save data in binary file

void save(WLIST *t,char *m)
{
    FILE *fs;
    NODE *a=t->st;
    if(a==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    fs=fopen(m,"wb");
    while(a!=NULL)
    {
        fwrite(&a->s,sizeof(STU),1,fs);
        a=a->next;
    }
    fclose(fs);
}

//function to build list from file data

void read(WLIST *t,char *m)
{
    FILE *fs;
    NODE *a=t->st,*b;
    STU data;
    fs=fopen(m,"rb");
    if(fs==NULL)
    {
        printf("\nFile does not Exist");
        return;
    }
    if(t->st!=NULL)
    {
        while(t->st!=NULL)
        {
            a=t->st;
            t->st=a->next;
            free(a);
        }
        t->cnt=0;
    }
    while(1)
    {
        fread(&data,sizeof(STU),1,fs);
        if(feof(fs))
          break;
        a=(NODE *)malloc(sizeof(NODE));
        a->s=data;
        a->next=t->st;
        t->st=a;
        t->cnt++; 
    }
    fclose(fs);
}

//Function using selection sort

void sort(WLIST *p)
{
    NODE *a=p->st,*b,*c;
    STU tmp;
    while(a->next!=NULL)
    {
        b=a;
        for(c=b->next;c!=NULL;c=c->next)
        {
            if(c->s.rno<b->s.rno)
               b=c;
            if(a!=b)
            {
                tmp=a->s;
                a->s=b->s;
                b->s=tmp;
            }
        }
        a=a->next;
    }
}
