#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
//tc O(V*E) sc O(V+E)
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        //find shortest dis from all nodes
        vector<int>dist(V,1e8);
        dist[S] = 0;//source
        for(int i=0;i<V-1;++i){
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u]+wt < dist[v])
                    dist[v] = dist[u] + wt;
            }
        }
        //nth relaxation to check -ve cycle exists
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u]+wt < dist[v])
                return {-1};
        }
        return dist;
    }
};

