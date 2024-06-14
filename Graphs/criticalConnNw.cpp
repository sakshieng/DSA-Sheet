// https://leetcode.com/problems/critical-connections-in-a-network/description/
// https://maang.in/mocks/attempts/2331?problem_id=62
//bridges in a graph
// critical connc is a connection that, if removed, will make some servers unable to reach some other server (logic -> if it is not a cycle it is a critical connc)
// Tarjan's Bridge-Finding Algorithm (TBFA).
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

/*
time[] -> store time of insertion during dfs
low[] -> min of all adjacent nodes apart from parent
*/

//TC O(2E+V) SC O(2E+V)+O(3N)
class Solution
{
private:
    int timer = 1;
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,int time[],int low[],vector<vector<int>>&bridges){
        vis[node]=1;
        time[node]=low[node]=timer;
        timer++;
        for(auto &it:adj[node]){
            if(it == parent) 
                continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,time,low,bridges);
                //what's ur lowest time apart from parent
                low[node] = min(low[node],low[it]);
                //if adjacent node has time lower than or equal to curr node insertion time then it is not a bridge
                if(low[it] > time[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],time[it]);//if it is not a bridge then update the lowest time of the node
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int>adj[n];
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        int time[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,-1,adj,vis,time,low,bridges);
        return bridges;
    }
};
