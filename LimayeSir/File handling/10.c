// program to read result.txt
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
    fs = fopen("result.txt", "r");
    if (fs == NULL)
    {
        printf("\nFile not found");
        return;
    }
    printf("\nResult\n");
    while (1)
    {
        fscanf(fs, "%d %s %lf", &no, nm, &mrk);
        if (feof(fs))
            break;
        printf("\n%4d %-15s %lf", no, nm, mrk);
    }
    fclose(fs);
    return 0;
}