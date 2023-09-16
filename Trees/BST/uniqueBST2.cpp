#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/unique-binary-search-trees-ii/description/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//we have to make all BST
class Solution
{
public:
    vector<TreeNode *> solve(int s, int e)
    {
        vector<TreeNode *> ans;
        if (s > e)
        {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = s; i <= e; i++)
        {
            vector<TreeNode *> left = solve(s, i - 1);
            vector<TreeNode *> right = solve(i + 1, e);
            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *res = new TreeNode(i, l, r);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};
/*
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        vector<vector<int>> dis(n+1,vector<int>(m+1,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;
            for(int i=0;i<4;++i){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow,nCol},steps+1});
                }
            }
        }
        return dis;
    }
};
*/