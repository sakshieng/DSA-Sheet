// https://leetcode.com/problems/number-of-provinces/description/
#include<bits/stdc++.h>
//no island like going in 4 dirn we just need to find how many compo are present in graph
using namespace std;

class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],int n){
        //make the compo vis
        vis[node] = 1;
        for(auto &i:adj[node]){
            if(vis[i] == 0){
                dfs(i,vis,adj,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        //adj list
        vector<int>adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(vis[i] == 0){ //not vis
                cnt++;
                dfs(i,vis,adj,n);
            }
        }
        return cnt;
    }
};