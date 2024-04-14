#include<stdio.h>
#include<stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// LL resolution
struct student
{
    int no;
    char nm[15];
    struct student *next;
}p[10];
void init()
{
    int i=0;
    while (i < 10)
    {
        p[i].no=0;
        p[i].next='\0';
        i++;
    }
}
struct student* createNode(int n)
{
    struct student *a;
    a=(struct student*)malloc(sizeof(struct student));
    a->no=n;
    printf("\nEnter name:");
    scanf("%s",a->nm);
    a->next=NULL;
    return a;
}
// for linear probing hash method define kru
void insert()
{
    int no,hval;
    struct student *a,*b;
    while(1)
    {
        printf("\nEnter roll no:");
        scanf("%d",&no);
        if(no == 0)
            break;
        hval=hash(no);//use of hash func
        //prime area mdhe jaga ahe ka
        if(p[hval].no == 0)            
        {
            p[hval].no=no;
            printf("\nEnter name");
            scanf("%s",p[hval].nm);
            printf("\nInserted in prime area\n");
        }
        else
        {
            // overflow area mdhe insert krnar
            a=createNode(no);
            b=p[hval].next;//3 no cha prime area til no b la ala
            a->next=b;
            p[hval].next=a;//we are adding new node at begin
            printf("\nInserted in overflow area\n");
        }
    }
}
void search()
{
    int no,hval;
    struct student *a;
    while (1)
    {
        printf("\nEnter roll no to search\n");
        scanf("%d",&no);
        hval=hash(no);
        // record prime area mdhe ahet ka
        if(p[hval].no==no)
        {
            printf("\nName is:",p[hval].nm);
            printf("\nFound in prime area");
        }
        else
        {
            a=p[hval].next;
            // ll ahe overflow area til tyatil pratek node la visit
            while (a != NULL)
            {
                if(a->no == no)
                {
                    break;
                }
                a=a->next;
            }
            if(a==NULL) printf("\nNot found");
            else printf("\nName is: %s",a->nm);
        }
    }   
}

int main()
{
   //global array declare so direct func call
   init();
   insert();
   search();
   return 0;
}