#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
// Code by Sakshi:
//  LL implementation of stack
int main()
{
    int opt, d;
    SLIST p;
    init(&p);
    while (1)
    {
        printf("\nStack\n1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\nOption");
        scanf("%d", &opt);
        if (opt > 4)
            break;
        switch (opt)
        {
        case 1:
            scanf("%d", &d);
            addBeg(&p, d);
            break;
        case 2:
            if (p.st == NULL)
                printf("Underflow");
            else
                delFirst(&p);
            break;
        case 3:
            if (p.st == NULL)
                printf("Underflow");
            else
                printf("\nTop element:%d", p.st->data);
            break;
        case 4:
            if (p.st == NULL)
                printf("\nEmpty Stack");
            else
                display(&p);
        }
    }
    return 0;
}