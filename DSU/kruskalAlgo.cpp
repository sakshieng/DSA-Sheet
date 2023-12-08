//helps us to find MST
//implment by Disjoint set
//tc O(n*m*4 alpha)
//https://bit.ly/3eLuYvH
#include<bits/stdc++.h>
using namespace std;
class disjointSet
{
    vector<int> parent, rank,size;

public:
    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
        for (int i = 0; i <= n; ++i)
            size[i] = 1;
    }
    // give ultimate parent by path compression method
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        // ultimate parent of u,v
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        // belong to same component
        if (rank[ulp_u] < rank[ulp_v])
        {
            // smaller goes and attched to larger
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;//larger one will grow by size 1
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; 
        }else{
            //equal or greater still attach
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i < V;++i){
            for(auto it:adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        disjointSet ds(V);
        //sorting by edges
        sort(begin(edges),end(edges));
        int mstWt = 0;
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            //see if they are in same compo or not
            if(ds.findPar(u) != ds.findPar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};
