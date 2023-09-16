#include<bits/stdc++.h>
//https://leetcode.com/problems/best-team-with-no-conflicts/
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int>dp(n,-1);
        vector<pair<int,int>>arr(n,{0,0});
        //{age,scores}
        for(int i=0;i<n;++i){
            arr[i].first = ages[i];
            arr[i].second = scores[i];
        }
        sort(arr.begin(),arr.end());
        int score = 0;
        for(int i=0;i<n;++i){
            dp[i] = arr[i].second;
            for(int j=i-1;j >= 0;j--){
                //sorted arr by age
                if(arr[i].second >= arr[j].second){
                    dp[i] = max(dp[i],dp[j]+arr[i].second);//add max wala elmt to main LIS
                } 
            }
            score = max(score,dp[i]);
        }
        return score;
    }
};