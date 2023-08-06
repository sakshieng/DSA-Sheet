// collison resolution using linear probing
#include<stdio.h>
#include<stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖

struct student
{
    int no;
    char nm[15];
}p[10];
// array created
void init()
{
    int i=0;
    while (i < 10)
    {
        p[i].no=10;
        p[i].nm[0]='\0';//null value set keli
        i++;
    }
}
int hash(int n)
{
    return n%10;//modulo division method
}
void insert()
{
    int no,hval,i=0;//subscript var i
    while (1)
    {
        printf("\nRoll no:");
        scanf("%d",&no);
        if(no==0)
            break;
        hval=hash(no);
        if(p[hval].no==0)    
        //home address
        {
            p[hval].no=no;
            printf("\nName:");
            scanf("%s",p[hval].nm);
            printf("\nInsertion at home address");
            continue;
        }
        // home address not null means collision
        // we need to conduct probe for empty locn
        printf("\nCollision occured\n");
        for ( i = hval+1; i < 10; i++)
        {
            if (p[i].no == 0)
            {
                p[i].no=no;
                printf("\nName:");
                scanf("%s",p[i].nm);
                printf("\nInsertion on collision path");
                break;
            }
        }   
        // i less than 10 means there are no blanks
        if(i < 10)//circular search
            continue;
        for ( i = 0; i < hval; i++)
        {
            if(p[i].no == 0)
            {
                p[i].no=no;
                printf("\nName:");
                scanf("%d",p[i].nm);
                break;
            }
        }
    // sglech full ahe
        if(i==hval)
            printf("\nOverflow");
    }
    //hash value 3 milali pn 23 hi value nhi milali
}
void search()
{
    int no,hval,i=0;
    while (1)
    {
        printf("\nRoll no:");
        scanf("%d",&no);
        if(no==0)
            break;
        hval=hash(no);
        if(p[hval].no==no)    
        {
            printf("\nName:");
            printf("%s",p[hval].nm);
            printf("\nFound at home address");
            continue;
        }
        printf("\nSearch on collision path");
        for(i=hval+1;i<10;i++)
        {
            if(p[i].no==0)
            {
                printf("\nNamme:");
                printf("%s",p[i].nm);
                printf("\nFound at collision path");
                break;
            }
        }
    if(i<10)
        continue;
    for ( i = 0; i < hval; i++)
    {
        if(p[i].no==no)
        {
        printf("\nnName:");
        printf("%s",p[i].nm);
        printf("\nFound cyclic path");
        break;
        }
    }
    if(i==hval)
        printf("\nNot found");
    }
}
int main()
{
   init();
   insert();
   search();
   return 0;
}