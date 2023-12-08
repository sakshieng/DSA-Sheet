// if we visit the adjacent node which is not a parent if it is already vis then it is cycle for undirected ut holds true
// for dir graph for the same path the node should be vis again
// when vis=1 and path visited=1 la parat visit krto tevha cycle
#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution
{
private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        // traverse adj nodes
        for (auto it : adj[node])
        {
            // when node is not visited
            if (!vis[it])
            {
                if (dfs(it, adj, vis, pathVis) == 1)
                {
                    return 1;
                }
            }
            //if node has been previously vis but it has not visited on same path
            if(pathVis[it]) return 1;
        }

        pathVis[node] = 0;
        return 0;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis) == 1)
                    return 1;
            }
        }
        return 0;
    }
};
//tc O(v+e) sc O(2n)