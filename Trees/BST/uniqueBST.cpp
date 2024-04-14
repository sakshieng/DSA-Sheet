#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/unique-binary-search-trees/description/
//catalan series is exact same as no of structurally unique BST
class Solution {
public:
    int solveTab(int n){
        vector<int>dp(n+1,0);
        dp[0] = dp[1] = 1;
        //0 1 case already done
        for(int i=2;i <= n;++i){
            // i->no of nodes
            for(int j=1;j <= i;++j){
                //j->root node
                dp[i] += dp[j-1]*dp[i-j];//as i are no of nodes - root
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        // return solve(n,dp);
        return solveTab(n);
    }
};