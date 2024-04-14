// https://leetcode.com/problems/flower-planting-with-no-adjacent/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    bool isSafe(int node,vector<vector<int>>& graph, vector<int>& color, int n, int col) {//for checking if any adjacent node has same color
    if(color[node] != 0) return 0;
    for (auto it:graph[node]) {
        if (color[it] == col && color[it] != 0) return false;
    }
    return true;
}

bool solve(int node, vector<int>& color, int N, vector<vector<int>>&graph) {
    if (node == graph.size()) return true;//colored all nodes

    for (int i = 1; i <= 4; ++i) {
        if (isSafe(node, graph, color, N, i)) {
            color[node] = i;
            if (solve(node + 1, color, N, graph)) return true;
            color[node] = 0;//we have to erase that color if its not possible to color
        }
    }
    return false;
}

vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    
    vector<vector<int>> graph(n);
    for (auto &p : paths) {
        graph[p[0]-1].push_back(p[1]-1);
        graph[p[1]-1].push_back(p[0]-1);
    }
    vector<int> color(n , 0);//none of the nodes colored hence initialize to 0
    solve(0, color,n, graph); 
    return color;
    }
};