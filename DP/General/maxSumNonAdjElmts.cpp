// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{
    //max sum of subseq that no 2 elmts are adajcent
    int n = nums.size();
    if(n == 0)
        return 0;
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= n; i++)
    {
        int pick = dp[i-2] + nums[i-1];
        int nonPick = dp[i-1] + 0;
        dp[i] = max(pick,nonPick);
    }
    return dp[n];
}