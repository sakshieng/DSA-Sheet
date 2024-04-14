#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// implementation of graph using adjacency list for directed graph
int main()
{
   int n,m;
   cin>>n>>m;
//    vector<int>degree(n+1,0);
   vector<int>indegree(n+1,0);
   vector<int>outdegree(n+1,0);
   vector<int>adj[n+1];//vector of array
   for (int i = 0; i < m; i++)
   {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    // adj[v].push_back(u);
    // degree[u]++;
    // degree[v]++;
    // u-->v
    indegree[v]++;
    outdegree[u]++;
   }
   for (int i = 1; i <= n; i++)
   {
    cout<<i<<":"<<indegree[i]<<":"<<outdegree[i]<<endl;
   }
   
//    for (int i = 1; i <= n; i++)
//    {
//     cout<<i<<"->"<<" ";
//     for(auto &edge:adj[i])
//     {
//         cout<<edge<<" ";
//     }
//     cout<<endl;
//    }
   return 0;
}
