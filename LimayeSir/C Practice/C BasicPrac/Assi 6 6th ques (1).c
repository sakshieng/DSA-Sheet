#include<stdio.h>
#include<math.h>
int main()
{
    float P,R,N,A,C;
    //C=compound interest,A=final amount
    printf("Formula of simple interest:%f/n",A);
    scanf("%f %f %f %f %f",&P,&R,&N,&A,&C);
    A=(P*R*N)/100;
    printf("Formula of compound intrest:%f/n",C);
    C=P*(pow((1+R/100),N));
    return 0;
}