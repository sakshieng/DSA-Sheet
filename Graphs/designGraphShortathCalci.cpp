#include<bits/stdc++.h>
//https://leetcode.com/problems/design-graph-with-shortest-path-calculator//?envType=daily-question&envId=2023-11-11
using namespace std;

class Graph {
private:
    int solve(int start,int end){
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap in pair (dist,node)
        pq.push({0, start});
        while (!pq.empty())
    {
        int distTo = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        vector<pair<int, int>>::iterator it;
        for (auto it : adj[prev]) // iterate on adj list
        {
            int next = it.first;
            int nextDist = it.second;
            int newCost = dist[prev] + nextDist;
            if (dist[next] > newCost)
            {
                dist[next] = newCost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    return ((dist[end]==INT_MAX)?-1:dist[end]);
    }
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it:edges)
            adj[it[0]].emplace_back(it[1],it[2]);
    }
    
    void addEdge(vector<int> edge) {
        //adding new edge to graph
        adj[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return solve(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */