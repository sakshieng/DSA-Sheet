#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
union pqr
{
    int a;
    char b;
    float c;
};
struct abc
{
    char type;
    union pqr var;
};
void main()
{
    int i = 0;
    char choice;
    struct abc p[5];
    while (i < 5)
    {
        printf("\nChoice:\ni-int\nc-char\nf-float\noption:");
        scanf("%c", &p[i].type);
        switch (p[i].type)
        {
        case 'i':
            printf("\nint data");
            scanf("%d", &p[i].var.a);
            break;
        case 'c':
            printf("\nchar data");
            scanf("%c", &p[i].var.b);
            break;
        case 'f':
            printf("\nfloat data");
            scanf("%f", &p[i].var.c);
            break;
        }
        i++;
    }
    printf("\nOutput:\n");
    i = 0;
    while (i < 5)
    {
        switch (p[i].type)
        {
        case 'i':
            printf("\n%d", p[i].var.a);
            break;
        case 'c':
            printf("\n%c", p[i].var.b);
            break;
        case 'f':
            printf("\n%f", &p[i].var.c);
        }
        i++;
    }
}
