#include <stdio.h>
#include <stdlib.h>
#include "clist.h"
// Code by Sakshi:

int main()
{
    int opt, d;
    CLIST p;
    init(&p);
    NODE *a, *b, *c;
    while (1)
    {
        printf("\nMenu:\n");
        printf("\n1.Create list\n2.Add at end\n3.Add at begin\n4.Delete first node\n5.Delete last node\n6.To display\n7.Exit");
        printf("Option: ");
        scanf("%d", &opt);
        if (opt > 7)
            break;
        switch (opt)
        {
        case 1:
            createNode(d);
            break;
        case 2:
            scanf("%d", &d);
            addEnd(&p, d);
            break;
        case 3:
            addBegin(&p, d);
            break;
        case 4:
            delFirst(&p);
            break;
        case 5:
            delLast(&p);
            break;
        case 6:
            display(&p);
            break;
        }
    }
}