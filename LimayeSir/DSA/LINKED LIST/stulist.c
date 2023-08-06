#include<stdio.h>
#include<stdlib.h>
#include "stulist.h"
//Code by Sakshi:

void main()
{
    // p.st represents address of next node
    // as it is structure ahe ani data type stu type cha ahe so binary file
    WLIST p;
    int opt, no;
    char nm[15];
    NODE *res;
    init(&p);
    while (1)
    {
        printf("\nMenu\n1.Add new record\n2.Modify existing record\n3.Delete\n4.Display all\n5.Search number\n6.Search name\n7.Save data in binary file\n8.Read\n9.Sort\n10.Exit\nOption:");
            scanf("%d",&opt);
        if(opt>9)    
            break;
        switch (opt)
        {
        case 1:
            add(&p);
            break;
        case 2:
            mod(&p);
            break;
        case 3:
            del(&p);
            break;
        case 4:
            displayAll(&p);
            break;
        case 5:
            printf("\nRoll no to search:");
            scanf("%d", &no);
            res = searchno(&p, no);
            if (res == NULL)
                printf("\nNot found");
            else
                display(&res->s);
            break;
        case 6:
            printf("\nEnter name to search:");
            scanf("%s", nm);
            res = searchnm(&p, nm);
            if (res == NULL)
                printf("\nNot found");
            else
                display(&res->s);
                break;
                // fnm char array having file
        case 7:
            save(&p);break;
        case 8:
            read(&p);break;
        case 9:
            sort(&p);
            displayAll(&p);
            break;
        }
    }
}
