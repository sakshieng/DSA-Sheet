#include<stdio.h>
#include<stdlib.h>
//Code by Sakshi:
#define M 10
// conversion to postfix expression
typedef struct stack
{
    int top;
    int arr[M];
}STK;
void init(STK *t)
{
    t->top = -1;
}
int isEmpty(STK *t)
{
    return t->top==-1;
}
int pop(STK *t)
{
    return (t->arr[t->top--]);
}
void push(STK *t,int d)
{
    t->top++;
    t->arr[t->top]=d;
}
int comp(int a,int b,char opr)
{
    int res;
    switch(opr)
    {
    case '+':
        res=a+b;
        break;
    case '*':
        res=a*b;
        break;
    case '/':
        res=a/b;
        break;
    case '-':
        res=a-b;
        break;    
    }
    return res;
}
int main()
{
   char pstr[50],ch;
   int i=0,ind,a,b,res;
   static int val[26]; //sagle initialize 0 la hotat
   STK p;
   init(&p);
   printf("Enter postfix: ");
   scanf("%s",pstr);
   for(i=0;pstr[i]!='\0';++i)
   {
        ch=pstr[i];
        if(ch >= 65 || ch<=90)//capital
        {
            ind=ch-65;//b hya operand chi value static array mdhe 1 store honar
            printf("\nEnter value for %c",ch);
            scanf("%d",&val);
        }
   } 
   while (pstr[i]!='\0')
   {
        if(ch>=65 && ch<=90)
        {
            ind=ch-65;
            push(&p,val[ind]);
        }
        else
        {
            // it is operator
            b=pop(&p);
            a=pop(&p);
            res=comp(a,b,ch);
            push(&p,res);
        }
        i++;
   }   
   res=pop(&p);
   printf("\nResult:%d",res);
   return 0;
}