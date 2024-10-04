#include <bits/stdc++.h>
// https://leetcode.com/problems/validate-binary-tree-nodes/?envType=daily-question&envId=2023-10-17
using namespace std;
  

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
                adj[i].push_back(leftChild[i]);
            }
            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
                adj[i].push_back(rightChild[i]);
            }
        }
        
        // Find the root indegree 0 exactly one root
        int x = -1;
        for(int i = 0; i < n; ++i){
            if(indegree[i] == 0 and x == -1){
                x = i;
            }else if(indegree[i] == 0) return false;
        }
        if (x == -1) return false; // No root found

        vector<int> vis(n, 0);
        
        function<bool(int)> dfs = [&](int u) -> bool{
            vis[u] = 1;
            for(auto &it:adj[u]){
                if(!vis[it])
                {
                    if(!dfs(it))
                        return 0;
                }else
                    return 0;
            }
            return 1;
        };
        if(!dfs(x)) return 0; // Cycle detected
        
        // Ensure all nodes are visited
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false; // Unvisited node found
        }
        
        return true;
    }
};