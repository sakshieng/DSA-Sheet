#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/description/
class Solution {
public:
vector<pair<int,int>>intersection;
int n;
// standard knapsack DP take or not take
int searchNextMin(int i){
    int left = i,right = n;
    while(right > left+1){
        int mid = left + (right-left)/2;
        if(intersection[mid].first < intersection[i].second){
            left = mid;
        }else{
            right = mid;
        }
    }
    return right;
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //precomputation
        n = intervals.size();
        for(auto i:intervals){
            intersection.push_back({i[0],i[1]});
        }
        sort(intersection.begin(),intersection.end());
        //tabulation
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int j = searchNextMin(i);
            dp[i]=max(1+dp[j],dp[i+1]);
        }
        return n-dp[0];
    }
};