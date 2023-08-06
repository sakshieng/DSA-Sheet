// BST creation traversal searching and deletion
//  outdegree-->kiti child ahet ani indegree-->parent kiti ahet

#include <stdio.h>
#include <stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} NODE;
typedef struct binaryTree
{
    NODE *rt;   // root
    NODE *prnt; // parent
    NODE *curr; // current
} BST;
void init(BST *t)
{
    t->rt = NULL;
    t->prnt = t->curr = NULL;
}
NODE *createNode(int d)
{
    NODE *a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->left = a->right = NULL;
    return a;
}
// pre-order traversal
void preOrder(NODE *a)
{
    if (a != NULL)
    {
        printf("%4d", a->data);
        preOrder(a->left);
        preOrder(a->right);
    }
    else
        return;
}
// in-order traversal
void inOrder(NODE *a)
{
    if (a != NULL)
    {
        inOrder(a->left);
        printf("%4d", a->data);
        inOrder(a->right);
    }
    else
        return;
}
// post-order traversal
void postOrder(NODE *a)
{
    if (a != NULL)
    {
        postOrder(a->left);
        postOrder(a->right);
        printf("%4d", a->data);
    }
    else
        return;
}
void createTree(BST *t)
{
    NODE *a;
    int d;
    while (1)
    {
        printf("\nData:\n");
        scanf("%d", &d);
        if (d == 0)
        {
            break;
        }
        if (t->rt == NULL)
        {
            t->rt = createNode(d);
            // empty tree
        }
        else
        // we have t fing locn of next node so loop
        // means d is root of tree compare it with inserted node and insert properly to form BST
        {
            a = t->rt;
            while (1)
            {
                if (d < a->data)
                {
                    if (a->left == NULL)
                    {
                        a = createNode(d);
                        break;
                    }
                    else
                    {
                        a = a->left;
                    }
                }
                else
                {
                    if (a->right == NULL)
                    {
                        a = createNode(d);
                        break;
                    }
                    else
                    {
                        a = a->right;
                    }
                }
            }
        }
    }
}
int search(BST *t, int sv)
{
    // BST is global variable so automaticallu curr and prnt are getting updated
    int flg = 0;
    NODE *a = t->rt;
    while (a != NULL)
    {
        if (a->data == sv)
        {
            t->curr = a;
            flg = 1;
            break;
        }
        // found means flg=1 for child prnt mhnje tyacha nxt parent asnar
        else
        {
            if (sv < a->data)
            {
                t->prnt = a;
                a = a->left;
            }
            else
            {
                t->prnt = a;
                a = a->right;
            }
        }
    }
    return flg;
}
// insert honara nvin node t->rt la storr krun compare krte
void deleteNode(BST *t, int val)
{
    NODE *p, *q, *r, *s;
    if (search(t, val) == 0)
    {
        printf("\nNot found");
        return;
    }
    p = t->prnt;
    q = t->curr;
    // leaf node deletion
    if (q->left == NULL && q->left == NULL)
    {
        if (p->left == q)
            p->left = NULL;
        else
            p->right = NULL;
        free(q);
        printf("Leaf node deleted");
        return;
    }
    // internal node deletion
    if (q->left != NULL && q->right != NULL)
    {
        if (p->right == q)
        {
            r = q->left;
            while (r != NULL)
            {
                s = r;
                r = r->right;
            }
            s->right = q->right;
            p->right = q->left;
        }
        else
        {   
            r = q->right;
            while (r != NULL)
            {
                s = r;
                r = r->left;
            }
            s->left = q->left;
            p->left = q->right;
            free(q);
            return;
        }
    }
    // node having one child deletion
    if (p->left == q)
    // left child
    {
        if (q->right == NULL)
            p->left = q->left;
        else
            p->left = q->right;
        free(q);
        return;
    }
    if (p->right == q)
    // right child
    {
        if (q->right == NULL)
            p->right = q->left;
        else
            p->right = q->right;
        free(q);
        return;
    }
}
// func with outdegree 1
int countD1(NODE *a)
{
    int i = 0;
    if (a == NULL)
        return 0;
        // leaf node
    if (a->right == NULL && a->left == NULL)
        return 0;
        // node with one child
    if (a->right == NULL || a->left == NULL)
    {
        printf("%4d", a->data);
        i = 1 + countD1(a->left) + countD1(a->right);
        return i;
    }
    // node with both child
    i = 1 + countD1(a->left) + countD1(a->right);
    return i;
}
// func with outdegree 2
int countD2(NODE *a)
{
    int i;
    if(a == NULL)
        return 0;
    if(a->left==NULL && a->right==NULL)        
        return 0;
    if(a->left==NULL || a->right==NULL)        
    {
        i=countD2(a->left)+countD2(a->right);
        return i;
    }
    i=1+countD2(a->left)+countD2(a->right);
    return i;
}
// func to copy the tree
NODE *copyTree(NODE *a)
{
    NODE *p=NULL;
    if(a != NULL)
    {
        p=(NODE *)malloc(sizeof(NODE));
        p->data=a->data;
        p->left=copyTree(a->left);
        p->right=copyTree(a->right);
    }
    return p;
    // this func will copy p.rt tree and stores it to q.rt then it will print inorder traversal
}
// func to mirror the tree
// supose tree having 5 levels start from bottom first leaft nodes swap then their parents and above above ja
NODE *mirrorTree(NODE *a)
{
    NODE *p=NULL;
    if(a != NULL)
    {
        p=a->left;
        a->left=mirrorTree(a->right);
        a->right=mirrorTree(p);
    }
    return a;
}
int main()
{
    int opt, d, sv, rvs;
    BST p,q;
    init(&p);
    init(&q);
    while (1)
    {
        printf("\nBinary search tree\nmenu\n1.create tree\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.Delete node\n9.count nodes with outdegree 1\n10.count nodes with outdegree 2\n12.copy tree\n13.exit\noption");
        scanf("%d", &opt);
        if (opt > 4)
            break;
        switch (opt)
        {
        case 1:
            createTree(&p);
            break;
        case 2:
            printf("\nInorder\n");
            inOrder(p.rt);
            break;
        case 3:
            printf("\nPreorder\n");
            preOrder(p.rt);
            break;
        case 4:
            printf("\nPostorder\n");
            postOrder(p.rt);
            break;
        case 5:
            printf("\nEnter search value: ");
            scanf("%d", &sv);
            res(p, sv);
            if (res == NULL)
                printf("Found");
            else
                printf("Not found");
        case 6:
            printf("\nEnter data to be deleted: ");
            scanf("%d", &d);
            deleteNode(&p, d);
            break;
        case 9:
            countD1(p.rt);
            break;
        case 10:
            printf("\nNodes with outdegree 2: ",countD2(p.rt));
            break; 
        case 12:
            init(&q);
            // as at the time of case we have to initialize the tree again
            q.rt=copyTree(p.rt);
            printf("\nInorder\n");
            inOrder(q.rt);
            break;  
        case 13:
            init(&q);
            q.rt=copyTree(p.rt);
            q.rt=mirrorTree(p.rt);
            printf("\nInorder\n");
            inOrder(q.rt);
            break;                                     
        }
    }
    return 0;
}
int i;
