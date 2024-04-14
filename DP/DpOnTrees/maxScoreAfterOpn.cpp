#include<bits/stdc++.h>
//https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/description/
//leetcode contest 370
using namespace std;

class Solution {
public:
// A tree is healthy if sum of values on path from root to any leaf node is diff zero
//tc O(v+e) sc O(v+e)
    long long dfs(int node,vector<bool>&vis,vector<vector<int>>&adj, vector<int>& values){
        vis[node] = 1;
        long long sum = 0;
        //traverse neighbours
        for(auto it:adj[node])
            if(!vis[it])
                sum += dfs(it,vis,adj,values);
        
        if(sum == 0)//for leaf node
            return (long long) values[node];
        return min(sum,(long long)values[node]);
    }
    long long maximumScoreAfterOperations(vector<vector<long long>>& edges, vector<int>& values) {
      int n = values.size();
      //store graph using adj list
      vector<vector<int>>adj(n);
      for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
      } 
      //find sum of all tree val
      long long total = accumulate(begin(values),end(values),0LL);
      //to make tree healthy we have to leave some nodes
      vector<bool>vis(n,0);
      long long leftOut = dfs(0,vis,adj,values);
      return total-leftOut;
    }
};