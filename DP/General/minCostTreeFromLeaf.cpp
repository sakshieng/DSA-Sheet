#include<bits/stdc++.h>
using namespace std;
//dp+merge interval
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
class Solution {
public:
//2 variables left and right are changing so 2-D dp
    int solve(vector<int>& arr,map<pair<int,int>,int>& mp ,int left,int right,vector<vector<int>>& dp){
    //if i==j means there is no possibility of crreating non-leaf node it is giving leaf node
    if(left == right) 
        return 0;

    //if dp has already ans present
    if(dp[left][right] != -1) 
        return dp[left][right];
        
    int ans = INT_MAX;
    //for partitioning
    for(int i=left;i<right;++i){
        ans = min(ans,mp[{left,i}]*mp[{i+1,right}]+solve(arr,mp,left,i,dp)+solve(arr,mp,i+1,right,dp));
    }
    //store ans in dp
    return dp[left][right] = ans;
}
    int mctFromLeafValues(vector<int>& arr) {
        //we have to precompute
        int n = arr.size();
        map<pair<int,int>,int>mp;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<n;++i){
            mp[{i,i}] = arr[i];
            for(int j=i+1;j<n;++j){
                mp[{i,j}] = max(arr[j],mp[{i,j-1}]);
            }
        }
        // for(int i=0;i<arr.size();++i){
        //     for(int j=i;j<arr.size();++j){
        //         cout<<"for range "<<i<<"->"<<j<<" max is "<<mp[{i,j}]<<endl;
        //     }
        // }
        return solve(arr,mp,0,arr.size()-1,dp);
    }
};
/*
arr 6 2 4 
    0 1 2
    break as 0 ad 1 2
then leaf*leaf chi multiplication means root asnar u will get i f=t by figure
    break as 0 1 and 2
*/