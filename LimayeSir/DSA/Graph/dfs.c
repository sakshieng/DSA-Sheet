#include<stdio.h>
#include<stdlib.h>
#include "adjlist.h"
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// using adjacency list
int visited[M];
void dfs(int v)
{
    struct list *p;
    visited[v]=1;
    p=k[v];
    printf("%c",p->ch);
    while (p != NULL)
    {
        if(visited[p->data] == 0)
        {
            dfs(p->data);
        }
        else
        {
            p=p->next;
        }
    }
}
int mpin()
{
   crepteList();
   dfs(1);
   return 0;
}