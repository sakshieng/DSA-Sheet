#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define M 10
//Code by Sakshi:
// program to implement infix to postfix
typedef struct stack
{
    int top;
    char opr[M];//stack mdhe operator
}CSTK;

void init(CSTK *t)
{
    t->top = -1;
}

int isEmpty(CSTK *t)
{
    return t->top==-1;//true asel tr +1 return honar
}

void push(CSTK *t,char ch)
{
    t->top++;
    t->opr[t->top]=ch;
}

char pop(CSTK *t)
{
    return t->opr[t->top--];
}

int preced(char stkTop,char opr)
{
    if(stkTop != '(' && opr == ')')
        return 1;
    else    
        return 0;        
}
//preced 1 return krel jr left parenthesis milala tr
int main()
{
   CSTK s;
   char istr[40],pstr[40],ch;//istr=infix string , pstr==postfix string 
   int i=0,j=0;
   init(&s);
   printf("\nInfix Expression:");
   scanf("%s",istr);
   while (istr[i] != '\0')
   {
    if(isalpha(istr[i]))
   //istr[i] alphabet char mhnje operand mhnje postfix la add 
        pstr[j++]=istr[i];
    else
    {
        while (!isEmpty(&s) && preced(s.opr[s.top],istr[i]))
        // s.opr[s.top] top character
        {
            ch=pop(&s);
            pstr[j++]=ch;
        }
        if(isEmpty(&s) || istr[i] != ')')
            push(&s,istr[i]);
        else
            ch=pop(&s);    
    }    
    i++;
   }
   while (!isEmpty(&s))
   {
        pstr[j++]=pop(&s);
   }
   pstr[j]='\0';
   printf("\nPostfix:%s",pstr);
   return 0;
}