#include <stdio.h>
#include <stdlib.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
int adj[10][10], n;
int q[10], f = 0, r = -1;
int visited[10];
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

void bfs(int v)
{
    int k;
    visited[v] = 1;
    printf("%4d", v);
    q[++r] = v; // insert
    while (f <= r)
    {
        v = q[f++]; // remove
        for (k = 1; k <= n; k++)
        {
            if (adj[v][k] == 1 && visited[k] == 0)
            {
                q[++r] = k;
                visited[k] = 1;
                printf("%4d", k);
            }
        }
    }
}

int main()
{
    printf("\nVertices count: ");
    scanf("%d", &n);
    createMatrix();
    bfs(1);
    return 0;
}