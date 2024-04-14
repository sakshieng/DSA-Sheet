#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
void dfs(int node,int parent,unordered_map<int,vector<pair<int,int>>>&graph,vector<bool>&vis,vector<int>&depth){
    vis[node] = 1;
    depth[node] = d;
    for(auto &it:graph[node]){
        if(vis[it.first] == false){
            
        }
    }

}
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int>ans(n,0);
        unordered_map<int,vector<pair<int,int>>>graph;
        int start = -1;//source node
        for(auto it:edges){
            int u = it[0],v = it[1];
            graph[u].push_back({v,0});
            graph[v].push_back({u,0});
            if(graph[u].size() == 1){
                start = u;
            }
            if(graph[v].size() == 1){
                start = v;
            }
        }
        vector<int>depth(n,0);
        vector<int>
    }
};