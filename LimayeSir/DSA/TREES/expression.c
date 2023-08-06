#include <stdio.h>
#include <ctype.h>
// isAlpha func sathi hi file
#include <stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// expression trees
// input must be postfix operation
typedef struct node
{
    struct node *left;
    char ch;
    struct node *right;
} NODE;
typedef struct eTree
{
    NODE *rt;
} ETREE;
void init(ETREE *t)
{
    t->rt = NULL;
}
NODE *createNode(char a)
{
    NODE *b = (NODE *)malloc(sizeof(NODE));
    b->left = b->right = NULL;
    b->ch = a;
    return b;
}
struct Stack
{
    int top;
    NODE *arr[10];
} s;
void sinit() // stack initialization
{
    s.top = -1;
}
void push(NODE *a)
{
    s.top++;
    s.arr[s.top] = a;
}
NODE *pop()
{
    return s.arr[s.top--];
}
void preOrder(NODE *a)
{
    if (a != NULL)
    {
        printf("%c", a->ch);
        preOrder(a->left);
        preOrder(a->right);
    }
    else
        return;
}
void postOrder(NODE *a)
{
    if (a != NULL)
    {
        postOrder(a->left);
        postOrder(a->right);
        printf("%c", a->ch);
    }
    else
        return;
}
void inOrder(NODE *a)
{
    if (a != NULL)
    {
        inOrder(a->left);
        printf("%c", a->ch);
        inOrder(a->right);
    }
    else
        return;
}

int main()
{
    char p[100];
    NODE *x, *y, *z;
    ETREE q;
    int i = 0;
    init(&q);
    sinit();
    printf("\nEnter postfix expression: ");
    scanf("%s", p); // it not allows spacing in betn so this  is used
    while (p[i] != '\0')
    {
        // isAlpha character as alphabet check krtey
        if (isalpha(p[i]))
        {
            push(createNode(p[i]));
        }
        else
        {
            z=pop();
            x=pop();
            y=createNode(p[i]);
            y->right=z;
            y->left=x;
            push(y);
        }
        i++;
    }
    q.rt=pop();
    // root la root node cha address store krychay
    printf("\nPreorder ");
    preOrder(q.rt);
    printf("\nInorder ");
    inOrder(q.rt);
    printf("\nPostorder ");
    postOrder(q.rt);
    return 0;
}