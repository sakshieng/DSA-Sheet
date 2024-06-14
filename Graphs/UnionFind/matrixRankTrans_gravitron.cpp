// https://maang.in/mocks/attempts/2461?problem_id=516
// https://leetcode.com/problems/rank-transform-of-a-matrix/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class UnionFind {
public:
    unordered_map<int,int>parent;
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void Union(int u,int v){
        if(parent.count(u) == 0)
            parent[u] = u;
        if(parent.count(v) == 0)
            parent[v] = v;
        u = find(u);
        v = find(v);
        if(u != v)
            parent[u] = v;
    }
    //we have to grp elmts 
    //cells with same value have same rank
    unordered_map<int,vector<int>>getGrps(){
        unordered_map<int,vector<int>>grps;
        for (auto &&u : parent)
        {
            grps[find(u.first)].push_back(u.first);
        }
        return grps;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<int,vector<pair<int,int>>>mp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mp[matrix[i][j]].push_back({i,j});
        
        vector<int>rowRank(m+n,0);
        for (auto &&cells : mp)
        {
            // UnionFind uf;
            // for (auto &&[r,c] : cells)
            // {
            //     uf.Union(r,c+n);
            // }
            // for (auto &&[a,grp] : uf.getGrps())
            // {
            //     int maxRank = 0;
            //     for(int i:grp) maxRank = max(maxRank,rowRank[i]);
            //     for(int i:grp) rowRank[i] = maxRank+1;
            // }
            // for (auto &&[r,c] : cells)
            // {
            //     matrix[r][c] = rowRank[r];
            // }
        }
        return matrix;
    }
};