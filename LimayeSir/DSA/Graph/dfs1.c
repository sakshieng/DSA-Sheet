#include <stdio.h>
#include <stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// implementation of dfs usind adjacency list
/*
Adjacency Matrix
________________
    1 2 3 4 5
1   0 1 1 0 0
2   1 0 0 1 0
3   1 0 0 1 0
4   0 1 1 0 1
5   0 0 0 1 0
         1
      /     \
      2     3
      \     /
         4
         |
         5
*/
int adj[10][10], n; // n=no of vertices
int visited[10];
// func to create matrix
void createMatrix()
{
    int r, c;
    while (1)
    {
        printf("\nRow: ");
        scanf("%d", &r);
        printf("\nColumn: ");
        scanf("%d", &c);
        if (r == 0 && c == 0)
            break;
        if (r < 1 || r > n || c < 1 || c > n)
            continue;
        adj[r][c] = adj[c][r] = 1;
    }
}
void dfs(int v)
{
    int k;
    visited[v] = 1;
    printf("%4d", v);
    for (k = 1; k <= n; k++)
    {
        if (adj[v][k] == 1 && visited[k] == 0)
        // if edge exists betn v to k
        {
            dfs(k);
        }
    }
}

int main()
{
    printf("\nVertices count: ");
    scanf("%d", &n);
    createMatrix();
    dfs(1);
    return 0;
}