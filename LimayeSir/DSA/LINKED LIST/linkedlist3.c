#include<stdio.h>
#include<stdlib.h>
#include"slist.h"
void main()
{
    SLIST p,q;
    int opt,d,res,pos,sv,rv;
    init(&p);
    init(&q);
    while(1)
    {
        printf("\nMenu\n1.Add at end\n2.Add at begin\n3.display\n4.count\n5.sum\n6.max\n7.min\n8.del first node\n9.del last node\n.10.del all nodes\n11.reverse\n12.reverse whole data\n13.odd count\n14.even count\n15.dispaly odd\n16.display even\n17.sum after \n18.sum before\n19.delete ith pos node\n20.insert new node before ith \n21.insert new node after ith pos node\n22.search value\n23.search and replace\n24.copy list\n25.reverse copy\n26.Exit\noption:");
        scanf("%d",&opt);
        if(opt>25)
            break;
        switch(opt)
        {
        case 3:
            display(&p);
            break;
        case 4:
            printf("\nTotal Nodes:%d",p.cnt);
            break;
        case 5:
            printf("\nSum:%d",sum(&p));
            break;

        case 6:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
                printf("\nMax Data:%d",findMax(&p));
            break;
        case 7:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
                printf("\nMin Data:%d",findMin(&p));
                break;
        case 8:
            delFirst(&p);break;
        case 9:
            delLast(&p);break;
        case 10:
            delAll(&p);break;
        case 11:
            revDisplay(p.st);break;
        case 12:
            revList(&p);break;
        case 13:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
                printf("\nOdd data count:%d",oddCount(&p));
                break;
        case 14:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
                printf("\nEven data count:%d",evenCount(&p));
                break;

         case 15:
             if(p.st==NULL)
                printf("\nEmpty list");
            else
              {

                printf("\nOdd position data:");
                displayOddNodes(p.st);
              }
              break;

       case 16:
           if(p.st==NULL)
                printf("\nEmpty list");
            else
                {
                printf("\nEven position data:");
                displayEvenNodes(p.st);
                }
                  break;

        case 17:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
            sumA(&p);
            break;
        case 18:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
            sumB(&p);
            break;


        case 19:
            if(p.cnt==0)
                printf("\nEmpty list");
            else
            {
                printf("\nNode position to delete:");
                scanf("%d",&pos);
                deliNode(&p,pos);
            }
            break;
        case 20:
            if(p.cnt==0)
                printf("\nEmpty list");
            else
            {
                printf("\nNode position to insert before");
                scanf("%d",&pos);
                printf("\nEnter data:");
                scanf("%d",&d);
                insertB(&p,pos,d);
            }
            break;
        case 21:
            if(p.cnt==0)
                printf("\nEmpty list");
                else
           {
            printf("\nEnter position to insert after:");
            scanf("%d",&pos);
            printf("\nAdd Data:");
            scanf("%d",&d);
            insertA(&p,pos,d);
           }
           break;
        case 22:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
            {
                printf("\nsearch data:");
                scanf("%d",&sv);
                if(search(&p,sv)==NULL)
                    printf("not");
                printf("Found");
            }
        case 23:
            if(p.st==NULL)
                printf("\nEmpty list");
            else
            {
                printf("\nSearch value ");
                scanf("%d",&sv);
                printf("\nReplace value");
                scanf("%d",&rv);
                findRepl(&p,sv,rv);
            }
        case 24:
            delAll(&q);
            q=copyList(&p);
            display(&q);
            break;
        case 25:
            delAll(&q);
            q=reversecopy(&p);
            display(&q);
            break;
        default:
            printf("\nAdd data:");
            scanf("%d",&d);
            if(opt==1)
                addEnd(&p,d);
            else
                addBeg(&p,d);

    }
}
return;
}
