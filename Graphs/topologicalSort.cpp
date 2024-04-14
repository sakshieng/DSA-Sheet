#include <bits/stdc++.h>
// 𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    vector<int> visited(n + 1, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);//topo sort -> 1st node has least indegree 
        }
    }
    vector<int> topoSort;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);//node is pushed because node has least indegree
        for(auto &edge:adj[node])
        {
            indegree[edge]--;//once node is put in our final ans every other node connec to it gets its indegree reduced by 1
            if(indegree[edge] == 0)
            {
                q.push(edge);//next node in topo sort will be having least indegree
            }
        }
    }
    for(auto &it:topoSort)
    {
        cout<<it<<" ";
    }
    return 0;
}
//TC->O(V+E)