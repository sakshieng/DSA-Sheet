#include<stdio.h>
int main()
{
    int x[10];
    int i=1,pcnt=0,ncnt=0,zcnt=0;
    system("cls");
    while(i<10)
   {
        printf("x[%d]:",i);
        scanf("%d",&x[i]);
i++;
    }



    
   { if(x[i]>0)
    pcnt++;
    else
    ncnt++;

   }
printf("%d %d",ncnt,pcnt);
   
}