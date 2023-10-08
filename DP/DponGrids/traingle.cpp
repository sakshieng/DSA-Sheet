// Fixed Starting Point and Variable Ending 
// mostly in problems we start form n-1,m-1 but here 
// Point so we will start from upper side only
//f(0,0) min path sum from (0,0)
//tc for memo O(n^2) sc O(n^2)+recursion stack space
//recursion is always top-down u just backtrack to accumulate the result
#include<bits/stdc++.h>
//https://leetcode.com/problems/triangle/
//  https://bit.ly/3K1cvqv
using namespace std;

class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int j=0;j < n;++j) dp[n-1][j] = triangle[n-1][j];//fill up the last row
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};