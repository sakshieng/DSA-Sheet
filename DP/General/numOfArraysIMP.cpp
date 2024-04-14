#include<bits/stdc++.h>
//https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/?envType=daily-question&envId=2023-10-07
using namespace std;

class Solution {
public:

const int mod = 1e9+7;
int memo(int idx,int currMax,int currCost,int n,int m,int k,vector<vector<vector<int>>>&dp){
    if(currCost > k) return 0;
        if(idx == n){
            if(currCost == k) return 1;
            else return 0;
        }
        if(dp[idx][currMax][currCost] != -1) 
            return  dp[idx][currMax][currCost];
        //try all numbers
        int ans = 0;
        for(int i=1;i <= m;++i){//1 to m mdhla no pick krycha
            if(i > currMax){
                ans += memo(idx+1,i,currCost+1,n,m,k,dp);
            }else{
                ans += memo(idx+1,currMax,currCost,n,m,k,dp);
            }
            ans %= mod;
        }
    return dp[idx][currMax][currCost]=ans;
}
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return memo(0,0,0,n,m,k,dp);

    }
};
// Time Complexity : O(n * m * k * m) states * time for each state     
// Space : O(n * m * k * m)    dp vector