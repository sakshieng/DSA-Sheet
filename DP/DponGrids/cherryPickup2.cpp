/*fixed starting point and variable ending point
https://bit.ly/3KQELfy
https://leetcode.com/problems/cherry-pickup-ii/description/
in uniformity nature greedy will not work some are growing some are reduce
there is common cell both alice and bob visits so combine there recursion
base case are 2 types destination wali & out of bound wali
as both alice and bob are moving along rows same ch so i1,i2 peksha i fkt

|           |           |
i+1,j-1     i+1,j   i+1,j+1
these are 9 combinations
recursion tc O(3^n*3^n) sc O(n)
memo tc O(n*m*m)*9 sc O(n*m*m)
*/
#include <bits/stdc++.h>
// Flipkart OA que
using namespace std;

class Solution
{
public:
    int func(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp)
    {
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c)
            return -1e8; // not INT_MIN because INT_MIN+(-ve) overflow
        if(dp[i][j1][j2] != -1) 
            return dp[i][j1][j2];
        if (i == r - 1)
        {
            // if they are at last row if they are at same col add once but if diff then add both separately
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        // explore all paths of alice & bob simultaneously
        int maxi = -1e8;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1;dj2++){
                int val = 0;
                if(j1 == j2)
                    val = grid[i][j1];
                else 
                    val = grid[i][j1] + grid[i][j2];
                val += func(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
                maxi = max(maxi,val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        //int dp[r][c-alice][c-bob]
        int r = grid.size();
        int c= grid[0].size();
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return func(0,0,c-1,r,c,grid,dp);
    }
};