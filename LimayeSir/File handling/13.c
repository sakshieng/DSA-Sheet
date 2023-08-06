#include <stdio.h>
typedef struct student
{
    int rno;
    char nm[15];
    double mrk;
    int state;
    // 1 is valid and 0 is deleted
} STU;
// STU is of 27 bytes
void input(STU *b, int n)
{
    b->rno = n;
    // roll no has kept unique
    printf("\nName:");
    scanf("%s", b->nm);
    printf("\nMarks:");
    scanf("%lf", &b->mrk);
    b->state = 1;
}
void display(STU *b)
{
    printf("\nRecord\nRoll no:%d\nName:%s\nMarks:%lf", b->rno, b->nm, b->nm);
}
// globally declare file pointer
FILE *fs;
STU s;
int n;
// func to search STU record numberwise return -1 if not found o.w.return begin byte no of found record
int search(int no)
{
    int pos = 0;
    // the func call(rewind) shifts file pointer to begin of file
    rewind(fs);
    while (1)
    {
        // func call returns present file pointer position from begin of the file
        fread(&s, sizeof(STU), 1, fs);
        // v imp
        if (feof(fs))
        {
            pos = -1;
            break;
        }
        if (s.rno == no)
            break;
        // func call returns present file pointer position from begin of the file
        pos = ftell(fs);
    }
    return pos;
}
// func to add new STU record to the file
void add()
{
    int no, pos;
    printf("\nRoll no");
    scanf("%d", &no);
    pos = search(no);
    if (pos >= 0)
    {
        printf("\nRecord exists");
        return;
    }
    input(&s, no);
    fwrite(&s, sizeof(STU), 1, fs);
}
// func to modify student record
void mod()
{
    int pos, no;
    printf("\nRoll no:");
    scanf("%d", &no);
    pos = search(no);
    if (pos == -1 || s.state == 0)
    {
        printf("\nInvalid Record");
        return;
    }
    input(&s, no);
    // as func pointer is at last of char shift it to starting as otherwise it will read 27 bytes
    // library fun fseek is used to shift file pointer to the byte no pos from begin of file
    fseek(fs, pos, SEEK_SET);
    fwrite(fs, sizeof(STU), 1, fs);
}
// func to delete data from file
void del()
{
    int pos, no;
    printf("\nRoll no:");
    scanf("%d", &no);
    pos = search(no);
    if (pos == -1 || s.state == 0)
    {
        printf("\nInvalid Record");
        return;
    }
    s.state = 0;
    fseek(fs, pos, SEEK_SET);
    // SEEK_SET seeks pos from begin of file
    fwrite(fs, sizeof(STU), 1, fs);
}
// func to display student record
void displayAll()
{
    fseek(fs, 0, SEEK_SET);
    // SEEK_END from end & SEEK_CUR from current pos & SEEK_SET from beginning of the file
    while (1)
    {
        fread(&s, sizeof(STU), 1, fs);
        if (feof(fs))
            break;
        display(&s);
    }
    return;
}
void main()
{
    int opt;
    // the func call fopen searches for file stu.dat on the disc if file found it reads and loads it into the memory possible operations reading existing contetnts of the file writing them back and also allow to add or append new record to end of file if file not found the func call returns NULL
    fs = fopen("STU.dat", "r+b");
    if (fs == NULL)
    {
        fs = fopen("STU.dat", "wb");
        fclose(fs);
        fs = fopen("STU.dat", "r+b");
    }
    while (1)
    {
        printf("\nMenu\n1.Add\n2.Mod\n3.Del\n4.Display\n5.Search\n6.Exit");
        scanf("%d", &opt);
        if (opt > 5)
        {
            break;
        }
        switch (opt)
        {
        case 1:
            add();
            break;
        case 2:
            mod();
            break;
        case 3:
            del();
            break;
        case 4:
            displayAll();
            break;
        case 5:
            printf("\nRoll no to search:");
            scanf("%d", &n);
            if (search(n) == -1)
                printf("\nNot found");
            else
                display(&s);
        }
    }
    fclose(fs);
}