// program to store data in file
#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
    FILE *fs;
    int no;
    char nm[15];
    double mrk;
    fs = fopen("result.txt", "w");
    while (1)
    {
        printf("\nRoll no ");
        scanf("%d", &no);
        if (no == 0)
            break;
        printf("\nName:");
        scanf("%s", nm);
        printf("\nMarks");
        scanf("%lf", &mrk);
        fprintf(fs, "%d %s %lf\n", no, nm, mrk);
    }
    fclose(fs);
    return 0;
}