// https://unstop.com/code/practice/250151
#include <bits/stdc++.h>
using namespace std;

// The bias was defined as the sum of the depths of all tree nodes.
vector<vector<int>> adj;
vector<bool> vis;
vector<int> depth;
void dfs(int node, int distance)
{
    vis[node] = 1;
    depth[node] = distance;
    for (auto &child : adj[node])
    {
        {
            if (!vis[child])
                dfs(child, distance + 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // depth->0 root node->1
    dfs(1, 0);
    int bias = 0;
    for (int i = 1; i <= n; ++i)
    {
        bias += depth[i];
    }
    cout << bias << endl;
    return 0;
}