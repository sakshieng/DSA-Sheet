#include<stdio.h>
#include<stdlib.h>
//Code by Sakshi:

typedef struct node
{
    int coe;//coeffiecient
    int man;//mantissa
    struct node *next;
}NODE;
typedef struct polynomial
{
    NODE *st;
}POLY;
void init(POLY *t)
{
    t->st=NULL;
}

// func to create node
NODE *createNode(int c,int m)
{
    NODE *a;
    a=(NODE *) malloc(sizeof(NODE));
    a->coe=c;
    a->man;
    a->next=NULL;
    return a;
}

// func to create poly list
void createPoly(POLY *t)
{
    NODE *a,*b;
    int c,m;
    while (1)
    {
        printf("\nCoeffient\n");
        scanf("%d",&c);
        printf("\nMantissa\n");
        scanf("%d",&m);
        if(c==0 && m==0)
            break;
        if(t->st==NULL)            
            t->st=a=createNode(c,m);
        else
        {
            // b is last node
            if(m >= b->man)
            {
                printf("Invalid mantissa");
                continue;
            }
            a=createNode(c,m);
            b->next=a;
        }            
        b = a;
    }
    return;
}

// func to display polynoimial expression
void display(POLY *t)
{
    NODE *a=t->st;
    if(t->st == NULL)
        printf("\nEmpty polynomial expression");
    else
    {
        printf("\nPolynomial\n");
        while(a!=NULL)
        {
            if(a->coe > 0)
                printf("+");
            printf("%dX%d ",a->coe,a->man);
            a=a->next;                
        }
    }    
}

// func to make polynomial list empty
void delAll(POLY *t)
{
    NODE *a=t->st;
    while (t->st != NULL)
    {
        t->st = a->next;
        free(a);
        a=t->st;
    }
}

// func to add 2 poly
POLY add(POLY *p,POLY *q)
{
    NODE *a,*b,*c,*d;
    int co,ma;
    POLY r;
    init(&r);
    a=p->st,b=p->st;
    while (a && b)
    {
        if(a->man > b->man)
        {
            co=a->coe;
            ma=a->man;
            a=a->next;
        }
        else
        {
            if (b->man > a->man)
            {
                co=b->coe;
                ma=b->man;
                b=b->next;
            }
            else
            {
                co=a->coe + b->coe;
                ma=a->man;
                a=a->next;
                b=b->next;
            }
        }
        c=createNode(co,ma);
        if(r.st == NULL)
            r.st=c;
        else
            d->next=c;
        d=c;                        
    }
    while (a)
    {
        co=a->coe;
        ma=a->man;
        d->next=createNode(co,ma);
        d=d->next;
        a=a->next;
    }
    while (b)
    {
        co=b->coe;
        ma=b->man;
        d->next=createNode(co,ma);
        d=d->next;
        b=b->next;
    } 
    return r;
}

// func to subtract 2 poly
POLY subtract(POLY *p,POLY *q)
{
    NODE *a,*b,*c,*d;
    int co,ma;
    POLY r;
    init(&r);
    a=p->st,b=p->st;
    while (a && b)
    {
        if(a->man > b->man)
        {
            co=a->coe;
            ma=a->man;
            a=a->next;
        }
        else
        {
            if (b->man > a->man)
            {
                co=b->coe * -1;
                ma=b->man;
                b=b->next;
            }
            else
            {
                co=a->coe - b->coe;
                ma=a->man;
                a=a->next;
                b=b->next;
            }
        }
        c=createNode(co,ma);
        if(r.st == NULL)
            r.st=c;
        else
            d->next=c;
        d=c;                        
    }
    while (a)
    {
        co=a->coe;
        ma=a->man;
        d->next=createNode(co,ma);
        d=d->next;
        a=a->next;
    }
    while (b)
    {
        co=b->coe;
        ma=b->man;
        d->next=createNode(co,ma);
        d=d->next;
        b=b->next;
    } 
    return r;
}

// func to multiply 2 poly
void mul(POLY *p,POLY *q)
{
    NODE *a,*b,*c,*d,*e,*f;
    int co,ma;
    POLY r;
    init(&r);
    a=p->st,b=p->st;
    while (b != NULL)
    {
        a=p->st;
        while (a != NULL)
        {
            co=a->coe * b->coe;
            ma=a->man + b->man;
            if(r.st == NULL)
                r.st=c=d=createNode(co,ma);
            else
            {
                if(ma < d->man)
                {
                    d->next=createNode(co,ma);
                    d=d->next;
                }
                else
                {
                    if(ma==d->man)
                        d->coe+=co;
                    else
                    {
                        e=f=r.st;
                        while (e != NULL)
                        {
                            if(e->man==ma)
                            {
                                e->coe+=co;
                                break;
                            }
                            else
                            {
                                if (ma>e->man)
                                {   
                                    c=createNode(co,ma);
                                    f->next=c;
                                    c->next=c;
                                    break;
                                }  
                            }
                            f=e;
                            e=e->next;
                        }
                        
                    }
                                            
                }
            }   
            a=a->next;             
        }
        // r.st destination list 1st node
        //f chya next la new node c
        // navin mantisa chi term lahan asel tr add hoil
        b=b->next;
    }
    return r;
}

void main()
{
    POLY a,b,c,p,q,r;
    init(&a);
    init(&b);
    init(&c);
    init(&p);
    init(&q);
    // init(&r);
    printf("\nEnter 1^st polynomial data");
    createPoly(&a);
    display(&a);
    printf("\nEnter 2^st polynomial data");
    createPoly(&b);
    display(&b);
    r=add(&p,&q);
    display(&r);
    r=subtract(&p,&q);
    display(&r);
}