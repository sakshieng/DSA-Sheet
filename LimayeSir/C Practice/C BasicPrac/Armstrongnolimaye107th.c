#include <stdio.h>
void main()
{
    int no,tmp,dig,tot=0;
    printf("\nEnter a 3 digit number");
    scanf("%d",&no);
    for(tmp=no,tot=0;tmp>0;tmp/=10)
    {
        dig=tmp%10;
        tot+=(dig*dig*dig);
}  
  if(no==tot)
    printf("\nArmstrong");
    else
    printf("\nNon Armstrong");
    return;
}
/*very imp as we have to maintain the order of instructions in for() like if tmp/=10 is before
 the declaration of tmp>0 then wrong output will display*/