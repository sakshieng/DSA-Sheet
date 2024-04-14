// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/?envType=daily-question&envId=2023-12-29
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int dp[300][1001];
    //1 partition complete zhala tr max value of that parition is difficulty of partition
    //To work on the ith job, you have to finish all the jobs j <- imp
    //if this line is not there we would greedily pic max ani eka prtition mdhe teh taknar
    int solve(int idx,int d,vector<int>& jobDifficulty){
        if(idx == jobDifficulty.size() && d == 0)
            return 0;//difficulty 0
        if(idx == jobDifficulty.size() || d == 0) 
            return 1e9;
        if(dp[idx][d] != -1)
            return dp[idx][d];
        int maxi = 0,ans = 1e9;
        for(int i=idx;i < jobDifficulty.size();++i){
            maxi = max(jobDifficulty[i],maxi);
            int res = solve(i+1,d-1,jobDifficulty);//mhnje ek partiton kela
            if(res != 1e9)
                ans = min(ans,maxi+res);//summin up all difficulties of d partitions
        }
        return dp[idx][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return solve(0,d,jobDifficulty);
    }
};