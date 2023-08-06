// program to create a text file
#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
    FILE *f1;
    char ch;
    f1 = fopen("abc.txt", "w");
    //    the func call f1 searches for file abc.txt on the disc
    // if file found it read it and loads into memory and allows writing to the file
    // if file not found it creates a new file and allows writing to the file
    printf("\nType a charcter\n");
    while (1)
    {
        scanf("%c", &ch);
        if (ch == '#')
            break;
        fputc(ch, f1);
    }
    fclose(f1);
    return 0;
}