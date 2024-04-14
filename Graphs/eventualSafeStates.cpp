//terminal node = outdegree=0
//everyone who that leads to cycle(incoming edge to cycle)  or everyone who is part of cycle can never be a safe node
//use of concept of cycle detection in direc 
//for safe node all path should end at terminal node
//u do not reset path vis iff u do not get cycle
#include<bits/stdc++.h>
//https://leetcode.com/problems/find-eventual-safe-states/description/
// https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
using namespace std;

//tc O(V+E)+O(V) sc O(3n)

class Solution {
    private:
bool dfs(int node,vector<int> adj[], int vis[], int pathVis[],int check[])
    {

        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        // traverse adj nodes
        for (auto it : adj[node])
        {
            // when node is not visited
            if (!vis[it])
            {
                if (dfs(it, adj, vis, pathVis,check) == 1)
                {
                    return 1;
                }
            }
            //if node has been previously vis but it has not visited on same path
            if(pathVis[it]) return 1;
        }
        //dfs safe call means safe node
        check[node] = 1;
        pathVis[node] = 0;
        return 0;
    }

  public:
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        
        int vis[V] = {0};
        int pathVis[V] = {0};
        vector<int>safeNodes;
        int check[V] = {0};//mark for which are safe nodes
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                dfs(i, graph, vis, pathVis,check);//we will not break if we get cycle do all dfs calls
            }
        }
        for(int i=0;i<V;++i){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};


