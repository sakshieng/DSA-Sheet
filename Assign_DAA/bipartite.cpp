#include<bits/stdc++.h>
//https://leetcode.com/problems/is-graph-bipartite/description/
using namespace std;

class Solution {
public:
bool dfs(vector<int>&visited,vector<vector<int>>&graph,int node,int color,vector<int>&colors)
{
    visited[node]=1;
    // if(color==1) color=0;
    // if(color==0) color=1;
    color=1-color;
    colors[node]=color;
    for(auto &edge:graph[node])
    {
        if(colors[edge]==colors[node]) return false;
        if(!visited[edge])
        {
            if(!dfs(visited,graph,edge,color,colors))
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color=1;
        // bool flg=true;
        vector<int>colors(n+1,-1);
        vector<int>visited(n+1,0);
        for(int i=0;i<n;++i)
        {
            if(!visited[i])
            {
                visited[i]=1;
                if(!dfs(visited,graph,i,color,colors))
                return false;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    
    bool result = sol.isBipartite(graph);
    
    if(result) {
        cout << "The given graph is bipartite." << endl;
    } else {
        cout << "The given graph is not bipartite." << endl;
    }

    return 0;
}
