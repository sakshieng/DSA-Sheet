#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

vector<int> BFS(vector<int> adj[], int n)
{
    vector<int> visited(n + 1, 0);
    vector<int> bfs;
    for (int i = 1; i <= n; ++i)
    // for components
    {
        if (visited[i] == 0)
        // Not visited asla tr visited karaych na
        {
            queue<int> q;
            q.push(i); // n first node
            visited[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto &edge : adj[node])
                // given nodes che adjacent element traverse
                {
                    if (visited[edge] == 0)
                    {
                        q.push(edge);
                        visited[edge] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfs = BFS(adj, n);
    for (auto &i : bfs)
    {
        cout << i << " ";
    }
    return 0;
}
/*
1-5-2
  3
  4

1 5
2 5
3 4 5
4 3
5 2 1


ans=1 5 2 3 4
1 2 3 4 5
k k k k k
*/