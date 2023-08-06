#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//Code by Sakshi:

// 21 bytes
typedef struct student
{
    int rno;
    char nm[15];
    int mrk;
}STU;

// 23 bytes
typedef struct node
{
    STU s;
    struct node *next;
}NODE;

void input(STU *a,int no)
{
    a->rno=no;
    system("cls");
    // fflush(stdin);
    printf("\nName");
    scanf("%s",a->nm);
    printf("\nMarks:");
    scanf("%d",&a->mrk);
}

void display(STU *a)
{
    printf("\n%4d %-15s %4d",a->rno,a->nm,a->mrk);
}

// 4 bytes as *st ahe
typedef struct stulist
{
    NODE *st;
    // ptr to node
    int cnt;
}WLIST;

void init(WLIST *t)
{
    t->st = NULL;
    // t holds address of slist
    t->cnt = 0;
}

// func to search numberwise
NODE *searchno(WLIST *t,int no)
{
    NODE *a=t->st;
    while (a!=NULL)
    {
        if(a->s.rno==no)
        break;
        a=a->next;
    }
    return a;  
}

// func to search namewise
NODE *searchnm(WLIST *t,char *b)
{
    NODE *a=t->st;
    while (a!=NULL)
    {
        if(strcmp(a->s.nm,b) == 0)
        break;
        a=a->next;
    }
    return a;
}

// func to add new record
void add(WLIST *t)
{
    int no;
    NODE *a;
    printf("\nRoll no:");
    scanf("%d",&no);
    a = searchno(t, no);
    if (a != NULL)
    {
        printf("\nRecord exists");
        return;
    }
    a = (NODE *)malloc(sizeof(NODE));
    // create node
    input(&a->s, no);
    a->next = t->st; // added at begin
    // calling counter t->st
    t->st = a;
    t->cnt++;
}

// func to modify record
void mod(WLIST *t)
{
    int no;
    NODE *a;
    printf("\nRoll No:");
    scanf("%d", &no);
    a = searchno(t, no);
    if (a == NULL)
    {
        printf("\nRecord does not exist");
        return;
    }
    input(&a->s, no);
    // exist krt asel tr input func ne over write
}

// func to delete 
void del(WLIST *t)
{
    int no;
    NODE *a, *b, *c;
    printf("\nRoll No:");
    scanf("%d", &no);
    a = searchno(t, no);
    if (a == NULL)
    {
        printf("\nRecord does not exist");
        return;
    }
    if (a == t->st)
        t->st = a->next;
    else
    {
        b = t->st;
        while (b->next != a)
            b = b->next;
        b->next = a->next;
    }
    free(a);
    t->cnt--;
}

//func to display all data
void displayAll(WLIST *t)
{
    NODE *a = t->st;
    if (a == NULL)
        printf("\nEmpty list");
    else
    {
        while (a != NULL)
        {
            display(&a->s);
            a = a->next;
        }
    }
}

// STU is structure ani data type stu type cha ahe so binary file
// changing data then use text file
// function to write list data to the binary file
void save(WLIST *t)
{
    FILE *fs;
    NODE *a = t->st;
    if (a == NULL)
    {
        printf("\nEmpty list");
        return;
    }
    fs = fopen("stu.dat", "wb");
    // wb is func to write in a file
    while (a != NULL)
    {
        fwrite(&a->s, sizeof(STU), 1, fs);
        // variable cha address,size of argument to be passed, ,which file to be opened
        a = a->next;
    }
    fclose(fs);
}
//function to built list from file data
void read(WLIST *t)
{
    FILE *fs;
    NODE *a = t->st, *b;
    STU data;
    fs = fopen("stu.dat", "rb");
    if (fs == NULL)
    {
        printf("\nFile does not exist");
        return;
    }
    if (t->st != NULL)
    {
        // already aslela data delete kelay
        while (t->st != NULL)
        {
            a = t->st;
            t->st = a->next;
            free(a);
        }
        t->cnt = 0;
    }
    while (1)
    // end of file asel break
    {
        fread(&data, sizeof(STU), 1, fs);
        if (feof(fs))
            break;
        a = (NODE *)malloc(sizeof(NODE));
        a->s = data;
        a->next = t->st;
        t->st = a;
        t->cnt++;
    }
    fclose(fs);
}

//func to sort
void sort(WLIST *p)
{
    NODE *a = p->st, *b, *c;
    STU tmp;
    while (a->next != NULL)
    {
        b = a;
        for (c = b->next; c != NULL; c = c->next)
        {
            if (c->s.rno < b->s.rno)
                b = c;
        }
        if (a != b)
        {
            tmp = a->s;
            a->s = b->s;
            b->s = tmp;
        }
        a=a->next;
    }
}

/*
read(&p,fnm);
while(1)
{
    if(opt>9)
    {
        save(&p,fnm);
        break;
    }
}
*/