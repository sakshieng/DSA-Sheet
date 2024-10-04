#include<bits/stdc++.h>
//https://leetcode.com/problems/top-k-frequent-words/
using namespace std;


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        vector<string>ans;    
        for(auto &i:words)
            mp[i]++;
        priority_queue<pair<int,string>>pq;
        for (auto &i:mp)
        {
            pq.push({-i.second,i.first});
            if(pq.size() > k)
                pq.pop();
        }
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
    int solve(vector<int>& nums, int target,int i,vector<int>&dp){
        int sum
        if(nums.size() > target)

        if(dp[i]!=-1)
            return dp[i];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; ++i)
        dp[i][0] = true;
    dp[0][arr[0]] = true; // as base case when target is 0 at a[0] then it is accepted
    for (int idx = 1; idx < n; ++idx)
    {
        for (int target=1;target<=k;++target){
           bool nonPick = dp[idx-1][target];
           bool pick = false; 
           if (target >= arr[idx]){
            pick = dp[idx-1][target-arr[idx]];
           }
            dp[idx][target] = pick || nonPick;
        }
    }
    return dp[n-1][k];
    }
};
