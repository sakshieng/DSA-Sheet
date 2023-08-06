#include <stdio.h>
#include <stdlib.h>
#define M 10
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
typedef struct queue
{
    int fr, rr;
    int arr[M];
} Q;
// we have to declare array of type queue Q reserve 24 bytes ase 10 queues
Q p[10];
void init()
{
    int i = 0;
    while (i < M)
    {
        p[i].rr = -1;
        p[i].fr = 0;
        i++;
    }
}
int getIndex(int val, int pos)
{
    int index;
    switch (pos)
    {
    case 1:
        // rightmost index
        index = val % 10;
        break;
    case 2:
        // middle
        index = (val / 10) % 10;
        break;
    case 3:
        // leftmost
        index = val / 100;
        break;
    }
    return index;
}
void input(int *a)
{
    int i = 0;
    while (i < M)
    {
        printf("\nData:");
        scanf("%d", (a + i));
        if (*(a + i) < 100 || *(a + i) > 999)
        // value 3 digit ch asli pahije
        {
            printf("\nInvalid input");
            continue;
        }
        i++;
    }
}
void display(int *a, int flg)
{
    int i = 0;
    if (flg == 0)
        printf("Before sorting\n");
    else
        printf("\nAfter sorting\n");
    while (i < M)
    {
        printf("%4d", a[i++]);
    }
}
// 3ra queue ahe tyacha rear ek ne vadhla
// 3rya queue mdhla arr chi jth position mdhe a[i] janar
void insert(int *a, int pos)
{
    int i = 0, index, j;
    while (i < M)
    {
        index = getIndex(a[i], pos);
        j = ++p[index].rr;
        p[index].arr[j] = a[i];
        i++;
    }
}
// sarv queue mdhle element remove kryche ani over write kryche
void remque(int *a)
{
    int i = 0, j = 0, k = 0;
    while (i < M)
    {
        for (j = 0; j <= p[i].rr; j++)
        {
            a[k++] = p[i].arr[j];
        }
        i++;
    }
}
// radix navachya func mdhe 3 vela insert ani remove call kryche
void radix(int *a)
{
    int pos;
    while (pos <= 3)
    {
        init();
        insert(a, pos);
        remque(a);
        // p array empty houn a la over write honar
        pos++;
    }
}
int main()
{
    int x[M];
    input(x);
    display(x, 0);
    radix(x);
    display(x, 1);
    return 0;
}