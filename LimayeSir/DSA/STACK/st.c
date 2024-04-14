#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void StackPara(STK *p,char *m)
{
    int cnt=0,i=0;
    for(i=0;m[i]!='\0';i++)
    {
        if(m[i]=='(')
        {    
            push(p,'(');
            cnt++;
        }
        else if(m[i]==')')
        {
            if(p->top==NULL)
                break;
            else
                pop(p);
        }
    }
    if(m[i]!='\0')
        printf("\nExtra Right");
    else if(isEmpty(p))
    {
        if(cnt==0)
            printf("\nNo Paranthesis Present");
        else
            printf("\nComplete Paranthesis");
    }
    else
        printf("\nExtra Left");
}
int main()
{
    STK *p;
    init(&p);
    StackPara(&p);
}