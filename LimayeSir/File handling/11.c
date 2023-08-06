// program to implement search operation for roll no from file result.txt
#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
    FILE *fs;
    int no, rno, flg = 0;
    char nm[15];
    double mrk;
    fs = fopen("result.txt", "r");
    if (fs == NULL)
        return;
    printf("\nEnter roll number to search:");
    scanf("%d", &rno);
    while (1)
    {
        fscanf(fs, "%d %s %lf", &no, nm, &mrk);
        if (feof(fs))
            break;
        if (no == rno)
        {
            flg = 1;
            break;
        }
    }
    if (flg == 0)
        printf("\nNot found");
    else
        printf("\nFound \nNo:%d \nName:%s \nMarks:%lf", no, nm, mrk);
    fclose(fs);
    return 0;
}