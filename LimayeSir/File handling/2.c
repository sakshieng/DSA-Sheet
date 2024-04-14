// program to read the file
#include <stdio.h>
#include <stdlib.h>
#define Sakshi ios_base::sync_with_stdio(false);
#define Program cin.tie(NULL);
int main()
{
    FILE *f1;
    char ch;
    f1 = fopen("abc.txt", "r");
    //    the func call fopen searches for file abc.txt on the disc
    // if file found it reads it and loads it into memory
    //  possible operation : reading,existing contents of the file if file does not found func returns NULL indicating that func call has failed
    if (f1 == NULL)
    {
        printf("\nFile not found ");
        return;
    }
    printf("\nData\n");
    while (1)
    {
        ch = fgetc(f1); // func to read the character
        if (feof(f1))
            break;
        printf("%c", ch);
    }
    fclose(f1);
    return 0;
}