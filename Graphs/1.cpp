#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// implementation of graphs using adjacency matrix
int main()
{
   int n,m;
   cin>>n>>m;
//    n-nodes m-edges
   int adj[n+1][m+1];
    for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        adj[i][j]=0;
    }
   }
   for(int i=0;i<m;i++) 
   {
    // undirected graph
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
   }
    for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
        cout<<adj[i][j]<<" ";
    }
    cout<<endl;
   }
   return 0;
}
/*
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>>ans(V);
        for(int i=0;i<edges.size();++i){
            int a = edges[i].first;
            int b = edges[i].second;
            ans[a].push_back(b);
            ans[b].push_back(a);
        }
        return ans;
        
    }
*/
