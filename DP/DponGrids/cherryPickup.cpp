#include<bits/stdc++.h>
//https://leetcode.com/problems/cherry-pickup/
using namespace std;
//we hae first rwch bottom cell and then reach upwards starting cell
//to maximize the profit check by movid down/right
//4 cases go down|go right|go down and then right|go right and then down
//tc O(N^3) sc O(N^3)
class Solution {
public:
    int func(int i1, int j1, int i2, int n, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp)
    {
        //i1+j1 = i2+j2
        int j2 = i1+j1-j2;
                
        if (i1 >= n || j1 >= n || j2 >= n || i2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e8; // not INT_MIN because INT_MIN+(-ve) overflow
        if(dp[i1][j1][i2] != -1) 
            return dp[i1][j1][i2];
        if(i1==n-1 && j1==n-1)//if one reach end other can also reach end
            return grid[i1][j1];
        int tmp = 0;
        if(i1 == i2 && j1==j2)//both are on same cell only one will collect 
            tmp += grid[i1][j1];
        else    
            tmp += grid[i1][j1] + grid[i2][j2];
        // explore all paths
        int a = func(i1+1,j1,i2+1,n,grid,dp);
        int b = func(i1+1,j1,i2,n,grid,dp);
        int c = func(i1,j1+1,i2,n,grid,dp);
        int d = func(i1,j1+1,i2+1,n,grid,dp);

        tmp += max({a,b,c,d});
        return dp[i1][j1][i2] = tmp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return max(0,func(0,0,0,n,grid,dp));
    }
};