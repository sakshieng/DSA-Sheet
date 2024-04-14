#include <stdio.h>
#include <stdlib.h>
#include "stulist.h"

void main()
{
    NODE *res;
    int no,opt;
    WLIST p;
    char b[100];
    init(&p);
    printf("\nEnter file name to open :");
    scanf("%s",b);
    while(1)
    {
        printf("\nMenu :\n1.Add New Record\n2.Search Roll Number\n3.Search Name\n4.Modify Existing Record");
        printf("\n5.Delete Record\n6.Display all Student Record\n7.Save data in Binary file\n8.Build list from binary file");
        printf("\n9.Sort List");
        printf("\n10.Exit\nOption :");
        scanf("%d",&opt);
        if(opt>9)
           break;
        switch(opt)
        {
            case 1:
               add(&p);
               break;
            case 2:
               printf("Enter Roll Number to search :");
               scanf("%d",&no);
               //if(searchno(&p,no))
               //   printf("\nRecord Found");
               //else
               //   printf("\nRecord not found");
               res=searchno(&p,no);
               if(res==NULL)
                  printf("\nRecord not found");
               else
                  display(&res->s);  
               break;
            case 3:
               printf("\nEnter Name :");
               scanf("%s",&b);
               //if(searchnm(&p,b))
               //   printf("\nRecord Found");
               //else
               //   printf("\nRecord not found");  
               res=searchnm(&p,b);
               if(res==NULL)
                  printf("\nRecord not found");
               else
                  display(&res->s);
               break;
            case 4:
               mod(&p);
               break;
            case 5:
               del(&p);
               break;
            case 6:
               displayAll(&p);
               break;
            case 7:
               save(&p,b);
               break;
            case 8:
               read(&p,b);
               break;   
            case 9:
               sort(&p);
               displayAll(&p);
               break;          
        }
    }
}