#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/unique-paths-ii/description/
class Solution {
public:
    int memo(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && mat[i][j]) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int up = memo(i - 1, j, mat, dp);
        int left = memo(i, j - 1, mat, dp);
        return dp[i][j] = (up + left);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memo(m - 1, n - 1, obstacleGrid, dp);
    }
};