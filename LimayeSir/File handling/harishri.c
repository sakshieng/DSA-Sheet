#include <stdio.h>

typedef struct student 
{
    int rno;
    char nm[15];
    double mrk;
    int state ; //1 is valid , 0 is deleted record
}STU;

void input(STU *b,int n)
{
    b->rno=n;// as we want roll no to be fixed to perform opertaions
    printf("\nName :");
    scanf("%s",b->nm);
    printf("\nMarks :");
    scanf("%lf",&b->mrk);
    b->state=1;
}

void display(STU *b)
{
    printf("\nRecord :\nRoll No. :%d\nName :%s\nMarks :%lf",b->rno,b->nm,b->mrk);
}

FILE *fs;//file pointer 
STU s;

//function to search STU record numberwise
// return -1 if not found otherwise return begin byte no. of found record 

int search(int no)
{
    int pos=0;
    rewind(fs);
    //the function call (rewind) shifts file pointer to the begin of the file
    while(1)
    {
        fread(&s,sizeof(STU),1,fs);
        if(feof(fs))
        {
            pos=-1;
            break;
        }
        if(s.rno==no)
           break;
        pos=ftell(fs); //function call returns present file pointer position from begin of the file     
    }
    return pos;
}

//function to add STU record to the file

void add()
{
    int no,pos;
    printf("\nRoll No. :");
    scanf("%d",&no);
    pos=search(no);
    if(pos>=0)
    {
        printf("\nRecord Exists");
        return;
    }
    input(&s,no);
    fwrite(&s,sizeof(STU),1,fs);
}

void mod()
{
    int pos,no;
    printf("\nRoll No. :");
    scanf("%d",&no);
    pos=search(no);
    if(pos==-1  || s.state==0)
    {
        printf("\nInvalid Record ");
        return;
    }
    input(&s,no);
    fseek(fs,pos,SEEK_SET); //SEEK_SET seeks pos from begin of file 
    //library function used to shift file pointer to the byte number pos to begin of the file
    fwrite(&s,sizeof(STU),1,fs);
}
// putw-->write and getw-->read
void del()
{
    int pos,no;
    printf("\nRoll No. :");
    scanf("%d",&no);
    pos=search(no);
    if(pos==-1  || s.state==0)
    {
        printf("\nInvalid Record ");
        return;
    }
    s.state=0;
    fseek(fs,pos,SEEK_SET); //SEEK_SET seeks pos from begin of file 
    fwrite(&s,sizeof(STU),1,fs);
}

//function to display all student record

void displayAll()
{
    fseek(fs,0,SEEK_SET);//
    while(1)
    {
        fread(&s,sizeof(STU),1,fs);
        if(feof(fs))
           break;
        display(&s);   
    }
    return;
}

void main()
{
    int opt,n;
    //the function call fopen searches for the file stu.dat on the disc if file found it reads it amd loads it into the memory. possible operations reading existinf contetents of the file , writing them back and also allow to add or append new record at the end of file . if file not found function call returns NULL 
    fs=fopen("stu.dat","r+b");
    if(fs==NULL)
    {
        fs=fopen("stu.dat","wb");
        fclose(fs);
        fs=fopen("stu.dat","r+b");
    }
    while(1)
    {
        printf("\nMenu :\n1.Add\n2.Mod\n3.Delete\n4.Display\n5.Search\n6.Exit\nOption :");
        scanf("%d",&opt);
        if(opt>5)
           break;
        switch(opt)
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
                printf("\nRoll No. to search :");
                scanf("%d",&n);
                if(search(n)==-1)
                    printf("\nNot Found");
                else
                    display(&s);                     
        }   
    }
    fclose(fs);
}