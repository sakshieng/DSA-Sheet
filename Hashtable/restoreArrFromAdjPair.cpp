#include<bits/stdc++.h>
//https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/?envType=daily-question&envId=2023-11-10
using namespace std;
//the set soln wont work as we dont know who 2 are adj to each other so we have to treat pairs like edges of graph
//use the logic of adjcency list
class Solution {
public:
    unordered_map<int,vector<int>>graph;//1 number ani tyachi adj list
    void dfs(int node,int prev,vector<int>&ans){
        ans.push_back(node);
        for(int neighbor:graph[node])
        {
            if(neighbor != prev)
                dfs(neighbor,node,ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto &edge:adjacentPairs){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int root = 0;
        for(auto &i:graph){
            if(i.second.size() == 1){
                root = i.first;
                break;
            }
        }
        vector<int>ans;
        dfs(root,INT_MAX,ans);
        return ans;
    }
};