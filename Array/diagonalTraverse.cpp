#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/diagonal-traverse/
class Solution {
public:
//it could be solved by matrix techq but by seeing we can try BFS
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();      
        vector<int>ans;
        queue<pair<int,int>>q;
        q.push({0,0});
        bool flg = 0;
        while (!q.empty())
        {
            int size = q.size();
            vector<int>tmp(size);
            for (int k = 0; k < size; k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                int idx = flg == 0 ? k : size-k-1;
                tmp[idx] = mat[i][j];
                if(j == 0 && i+1 < n) 
                    q.push({i+1,j});
                if(j+1 < m)
                    q.push({i,j+1});
            }
            for(int x : tmp)
                ans.push_back(x);
            flg = !flg;
        }
        return ans;
    }
};