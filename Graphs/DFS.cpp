#include <bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// DFS-->recursion
void DFS(vector<int>adj[],int node,vector<int> &visited,vector<int> &dfs)
{
    visited[node]=1;
    dfs.push_back(node);
    for(auto &edge:adj[node])
    {
        if(visited[edge] == 0)
        {
            DFS(adj,edge,visited,dfs);
        }
    }
}
vector<int>dfsofGraph(int n,vector<int>adj[])
// store kryla aapn visited array same func mdhe nhi banvu shkt jithe rec call kelay
{
    vector<int>visited(n+1,0);
    vector<int>dfs;
    for(int i=1;i<=n;++i)
    {
        if(!visited[i])
        // for loop->components hya if chya aat gelo mhnje new compo mdhe gelo
        {
            DFS(adj,i,visited,dfs);
        }
    }
    return dfs;
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
    vector<int>dfs=dfsofGraph(n,adj);
    for(auto &i:dfs)
    {
        cout<<i<<" ";
    }
    return 0;
}
/*
    1               4
2       3               5

DFS--> 1 2 3
adj list
1: 2 3
2: 1
3: 1

*/