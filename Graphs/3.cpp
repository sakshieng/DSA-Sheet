#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
// adjacency list implementation for undirected graph
using namespace std;

int main()
{
   int n,m; 
   cout<<"\nVertices and edges: ";
   cin>>n>>m;
   int u,v;
   vector<int>adj[n];//vector of arrays
   for(int i=0;i<m;++i) 
   {
    cout<<"\nEnter edge values: ";
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }
//    display
// accessing when we are using element is O(1)
   cout<<endl<<"How this graph looks:"<<endl;
   for(int node=0;node<n;node++) 
   {
    cout<<node<<" : ";
    for(auto &child:adj[node])
    {
        cout<<child<<" ";
    }
    cout<<"\n";
   }
   return 0;
}
