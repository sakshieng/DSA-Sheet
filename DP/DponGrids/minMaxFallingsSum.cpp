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

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<m;++j) dp[0][j] = matrix[0][j];
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                int up = matrix[i][j] + dp[i-1][j];
                int leftdown = matrix[i][j];
                if(j-1>=0) 
                    leftdown += dp[i-1][j-1];
                else
                    leftdown += 1e8;
                int rightdown = matrix[i][j];
                if(j+1 < m)
                    rightdown += dp[i-1][j+1];
                else 
                    rightdown += 1e8;
                dp[i][j] = min(up,min(leftdown,rightdown));
            }
        }
        int mini = INT_MAX;
        for(int j=0;j<m;++j) mini = min(mini,dp[n-1][j]);
        return mini;
    }
};