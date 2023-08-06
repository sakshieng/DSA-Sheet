#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

int findWays(vector<int> &num, int sum)
{
    long long n = num.size();

    vector<long long> prev(sum + 1, 0);

    prev[0] = 1;

    if (num[0] <= sum)
        prev[num[0]] = 1;

    for (long long ind = 1; ind < n; ind++)
    {
        vector<long long> cur(sum + 1, 0);
        cur[0] = 1;
        for (long long target = 1; target <= sum; target++)
        {

            long long nonPick = prev[target];

            long long pick = 0;
            if (num[ind] <= target)
                pick = prev[target - num[ind]];
            cur[target] = nonPick + pick;
        }
        prev = cur;
    }
    return prev[sum] % (long long)(1e9 + 7);
}
/*
#include<bits/stdc++.h>


long long f(vector<int>& arr,int ind,int sum,vector<vector<long long>>& dp){
	if(sum==0) return 1;
	if(ind==arr.size()-1){
		if(arr[ind]==sum) return 1;
		return 0;
	}
	if(dp[ind][sum]!=-1) return dp[ind][sum];
	long long pick=0;
	if(arr[ind]<=sum) pick=f(arr,ind+1,sum-arr[ind],dp);
	long long notpick=f(arr,ind+1,sum,dp);
	return dp[ind][sum]=(pick+notpick)%(int)(1e9+7);
}

int findWays(vector<int>& arr, int sum)
{
	// Write your code here.
	vector<vector<long long>> dp(arr.size(),vector<long long>(sum+1,-1));
	return f(arr,0,sum,dp);
}

*/
