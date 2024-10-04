// https://www.geeksforgeeks.org/problems/path-in-matrix3805/1
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> grid)
    {
        vector<vector<int>>dp(n,vector<int>(n,0));
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = grid[0][j];
        }
        for(int i = 1;i < n;++i){
            for (int j = 0; j < n; j++)
            {
                int up = dp[i-1][j];
                int upLeft = (i > 0) ? (dp[i-1][j-1]) : 0;
                int upRight = (j > 0) ? (dp[i][j-1]) : 0;//observe here we are not goiing with paths which are in given we are taking top-down
                //we want max sum
                dp[i][j] = max({up,upLeft,upRight}) + grid[i][j];
            }
        }
        //as thsi is tabulation we will take max value in dp table
        int maxi = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            maxi = max(maxi,dp[n-1][j]);
        }
        return maxi;
    }
};