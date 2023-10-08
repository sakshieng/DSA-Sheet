// https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/?envType=daily-question&envId=2023-09-17
#include<bits/stdc++.h>
using namespace std;

// in our path when we reach all nodes we have to stop
// bit masking+graph 
//bit=1 means node is visited


class Solution {
public:
    
    int solve(vector<vector<int>>&g){
        int n=g.size(); 
        int all = (1 << n) - 1; //11111
        
        queue<pair<int , pair<int, int>>>q; 
        // {i,{dist,mask}}
        set<pair<int, int>>vis;//no same elmts would be added in queue
        for(int i=0;i<n;i++)
        {
            int mask = (1<<i);
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int val = node.first , dist = node.second.first , mask = node.second.second;
            for(auto nbr : g[val]){
                int newMask = (mask | (1<<nbr)); //telling us which nodes are visited
                
                if(newMask == all)
                    return dist+1; 
                
                else if(vis.count({nbr, newMask})){//if its already in queue
                    continue; 
                }
                else{
                    q.push({nbr,{dist+1,newMask}});
                    vis.insert({nbr, newMask});               
                }
            }
        }
        return 0;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n=graph.size();
        if(n==1) 
            return 0;
        
        return solve(graph);
    }
};