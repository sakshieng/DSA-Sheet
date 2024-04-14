// https://leetcode.com/problems/tallest-billboard/editorial/
//we want 2 disjoint sets such that maximum sum of elmts would be there
#include<bits/stdc++.h>
using namespace std;
//if we find all possible combi then TC=O(3^n) as 1st set 2nd set and not included
//if we use dp then TC=O(n*sum) define dp as dp[diff] = taller-shorter as we have to maximize taller hence dp[diff] = max(dp[diff],taller)

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int>dp;
        dp[0]=0;//initially no rods
        for(auto &a:rods){
            unordered_map<int,int>tmp(dp);
            for(auto &it:dp){
                int diff = it.first;
                int taller = it.second;
                int shorter = taller-diff;
                //adding r to taler stand hence diff will increase by r
                int newTaller = tmp[diff+a];
                tmp[diff+a] = max(newTaller,taller+a);
                //adding r to shorter stand hence diff will decrease by r
                int newDiff = abs(shorter+a-taller);
                int newTaller2 = max(shorter+a,taller);
                tmp[newDiff] = max(tmp[newDiff],newTaller2);
            }
            dp = tmp;
        }
        return dp[0];
    }
};
