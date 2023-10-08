#include <bits/stdc++.h>
// O(n^2) tc 
// for undirected graph convert it in form of directed graph to apply this algo
using namespace std;
struct node
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    //    for shortest path from the source
    int src;
    cin >> src;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    //    relax for n-1 times
    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    int cnt = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative cycle";
            cnt = 1;
            break;
        }
    }
    if (!cnt)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << i << " " << dist[i] << endl;
        }
    }
    return 0;
}
