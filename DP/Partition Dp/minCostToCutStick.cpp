#include<bits/stdc++.h>    
// https://www.codingninjas.com/studio/problems/cost-to-cut-a-chocolate_3208460?source=youtube&campaign=striver_dp_videos&leftPanelTab=1
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
using namespace std;

class Solution {
public:
int c ;
int memo(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i > j) return 0;//partition is over
    int mini = INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    for(int idx = i;idx <= j;idx++){
        int costs = cuts[j+1]-cuts[i-1]+memo(i,idx-1,cuts,dp)+memo(idx+1,j,cuts,dp);
        mini = min(costs,mini);
    }
    return dp[i][j] = mini;
}

    int minCost(int n, vector<int>& cuts) {
        //cost = length of stick u cut
        c = cuts.size();
        cuts.push_back(n);//right partition
        cuts.insert(cuts.begin(),0);//first left partition
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        sort(cuts.begin(),cuts.end());//in order to make 2 subproblems independent
        return memo(1,c,cuts,dp);
    }
};