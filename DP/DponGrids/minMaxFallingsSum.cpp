// Variable Starting and Ending Points
// https://bit.ly/3F436dK
// https://leetcode.com/problems/minimum-falling-path-sum/description/
//find max sum start from any cell in 1st row to any cell in last row
//f(i,j) max path sum to reach (i,j) from any cell in first row
#include<bits/stdc++.h>
//recursion tc O(3^n) sc O(n)
//memo O(n*m) sc O(n*m)+O(n)
using namespace std;

class Solution {
public:
    int n;
    int memo(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (i == n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = mat[i][j] + memo(i + 1, j, mat, dp);
        if (j - 1 >= 0)
            ans = min(ans, mat[i][j] + memo(i + 1, j - 1, mat, dp));
        if (j + 1 < n)  // Fix the condition here
            ans = min(ans, mat[i][j] + memo(i + 1, j + 1, mat, dp));
        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();  
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)  
            ans = min(ans, memo(0, i, matrix, dp));

        return ans;
    }
};