// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
#include<bits/stdc++.h>
using namespace std;
//2d prefix sum standard que

int solve(vector<vector<char>>& grid,char ch){//grid block sum
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>>pre(n,vector<int>(m,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pre[i][j] = (grid[i][j] == ch);
            if(i > 0)
                pre[i][j] += pre[i-1][j];
            if(j > 0)
                pre[i][j] += pre[i][j-1];
            if(i > 0 && j > 0)
                pre[i][j] -= pre[i-1][j-1];
        }
    }
    return pre;
}
int numberOfSubmatrices(vector<vector<char>>& grid) {
    int n = grid.size(),m = grid[0].size();
    vector<vector<int>>xCount = solve(grid,
    'X');
    vector<vector<int>>yCount = solve(grid,
    'Y');
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += ((xCount[i][j] == yCount[i][j]) && (xCount[i][j] > 0));//they said x should be occur more than 1 time
        }
    }
    return ans;
}