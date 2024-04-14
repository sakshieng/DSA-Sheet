#include<stdio.h>
int main()
//aggregate marks are w.r.t. 3 subjects
{ 
    int phy,chem,maths,sci,civics;
    printf("enter the marks of subject\n");
    scanf("%d %d %d %d %d",&phy,&chem,&maths,&sci,&civics);
    printf("\nmarks:%s %s","marks","Total");
    printf("\n %d %d %d %d %d",phy=100,chem=100,maths=100,sci=100,civics=100);
    printf("\nTotal:%d",(100+100+100+100+100));
    printf("\nPercentage:%d",(((100+100+100+100+100+100)/500)*100));
    printf("\nAggeragate:%d",(100/3));
    return 0;
}