/*
time[] -> store the time of insertion during dfs
low[] -> min of all adjacent nodes apart from parent & visited nodes
do not do anything for first parent as if it is parent & it has multiple children then it is arti point
u may find the same arti point multiple times form hashing
*/
// https://www.geeksforgeeks.org/problems/articulation-point-1/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int timer=0;
    void dfs(int node, vector<int> adj[], vector<int> &vis, int time[], int low[], vector<int> &mark,int parent)
    {
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        //starting point ka logic
        int child = 0;
        for(auto &&i:adj[node]){
            if(i == parent) continue;
            if(!vis[i]){
                dfs(i,adj,vis,time,low,mark,node);
                low[node] = min(low[node],low[i]);//greedily take the lowest time
                if(low[i] >= time[node] && parent != -1)//u can't reach before me & u are first guy
                {
                    mark[node]=  1;//u are arti point
                }
                child++;
            }else{
                low[node] = min(low[node],time[i]);//as it is vis dont take low
            }
        } 
        if(child > 1 && parent == -1) mark[node] = 1;//multiple compo & i am parent then i am arti point
    }
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        
        int time[n], low[n];
        vector<int> mark(n, 0);
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, time, low, mark,-1);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            // if it is marked as an arti point
            if (mark[i] == 1)
                ans.push_back(i);
        }
        if (ans.size() == 0)
            return {-1};
        else
            return ans;
    }
};