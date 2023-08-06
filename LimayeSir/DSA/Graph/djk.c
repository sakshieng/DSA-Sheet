#include <stdio.h>
#include <stdlib.h>
#define INF 999
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// Dijkstra algorithm
int n, adj[10][10]; // adjacency matrix
void init()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            adj[i][j] = INF;
        }
    }
}
void createGraph()
{
    int s, d, val;
    init();
    while (1)
    {
        printf("\nS: D:");
        scanf("%d%d", &s, &d);
        if (s == 0 && d == 0)
            break;
        if (s < 1 || d < 1 || s > n || d > n)
            continue;
        printf("\nWeight: ");
        scanf("%d", &val);
        adj[s][d] = adj[d][s] = val;
    }
}
void djk()
{
    int s, d, curr, sd, nd, i;
    int visited[10], dist[10], preced[10];
    init();
    do
    {
        printf("\nSource: ");
        scanf("%d", &s);
        printf("\nDestination: ");
        scanf("%d", &d);
        if (s == 0 && d == 0)
            break;
        dist[s] = 0;
        preced[s] = 0;
        visited[s] = 1;
        curr = s;
        while (curr != d)
        {
            for (i = 0; i <= n; ++i)
            {
                nd = dist[curr] + adj[curr][i];
                if (nd < dist[i])
                {
                    dist[i] = nd;
                    preced[i] = curr;
                }
            }
            sd=INF;
            for(i=1;i<=n;++i)
            {
                if(visited[i]==0 && dist[i]<sd)
                {
                    sd=dist[i];
                    curr=i;
                }
            }
            visited[curr]=i;
        }
        printf("\nShortest distance:%d",dist[curr]);
        printf("\nPath:%d->",d);
        while (preced[curr] != s)
        {
            curr=preced[curr];
            printf("%d->",curr);
        }
    } while (1);
}
int main()
{
    printf("\nNode count: ");
    scanf("%d",&n);
    createGraph();
    djk();
    return 0;
}