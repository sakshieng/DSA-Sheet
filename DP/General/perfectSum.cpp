//same as subset sum equal k
// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution{
	public:
	int mod  = 1e9 + 7;
	int memo(int arr[], int n, int sum, int i,vector<vector<int>>& dp){
	    if(i >= n) return sum == 0;
	    if(dp[i][sum] != -1) return dp[i][sum];
	    int pick = 0;
	    if(sum >= arr[i]) pick = memo(arr,n,sum - arr[i],i+1,dp);
	    int nonPick = memo(arr,n,sum,i+1,dp);
	    nonPick %= mod;
	    pick %= mod;
	    return dp[i][sum] = (pick + nonPick)%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return memo(arr,n,sum,0,dp)%mod;
	}
	  
};