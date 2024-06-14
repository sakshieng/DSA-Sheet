#include <bits/stdc++.h>
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

void solve()
{
    int n = 5; // Number of vertices
    int m = 10; // Number of edges

    vector<node> edges;
    edges.push_back(node(0, 1, 6));
    edges.push_back(node(0, 2, 7));
    edges.push_back(node(1, 2, 8));
    edges.push_back(node(1, 3, 5));
    edges.push_back(node(1, 4, -4));
    edges.push_back(node(3, 1, -2));
    edges.push_back(node(3, 1, 1));
    edges.push_back(node(2, 3, -3));
    edges.push_back(node(2, 4, 9));
    edges.push_back(node(4, 3, -7));

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
    return;
}

int main()
{
    solve(); 
    return 0;
}
