#include<bits/stdc++.h>
// https://leetcode.com/problems/maximum-earnings-from-taxi/
using namespace std;

class Solution {
public:
unordered_map<long long,long long>dp;
int find(vector<vector<int>>& rides,int start,int toFind){
    int low = start;
    int high = rides.size()-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(rides[mid][0] >= toFind){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
long long ans(vector<vector<int>>& rides,int i){
    if(i >= rides.size()){
        return 0;
    }
    if(i<0) return 0;
    if(dp.find(i) != dp.end()) return dp[i];
//my start should be greater than my prev taken end time
    int idx = find(rides,i+1,rides[i][1]);//curr person
    long long take = rides[i][1]-rides[i][0]+rides[i][2]+ans(rides,idx);
    long long notTake = ans(rides,i+1);
    return dp[i] = max(take,notTake);
}
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        return ans(rides,0);
    }
};