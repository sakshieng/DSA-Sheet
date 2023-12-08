/*strictly increasing means no duplicate values
num1 -1 1 2 5 4 
num2 -1 1 3 3 7
for the swap condn we are checking 
num1>prev2 && num2>prev1
means 
5>3 && 3>2 yes ->idx=3 at 5(cross check ahe)
so add it to ans
for no swap
num1>prev1 && num2>prev2
2>1 && 3>1 no swap
*/
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int solve(vector<int>& nums1, vector<int>& nums2,int idx,bool isSwap,vector<vector<int>>&dp){
    if(idx == nums1.size())//out of bound
        return 0;
    if(dp[idx][isSwap] != -1)
        return dp[idx][isSwap];
    int ans = INT_MAX;
    int prev1 = nums1[idx-1];
    int prev2 = nums2[idx-1];
    //catch
    if(isSwap)
        swap(prev1,prev2);
    // no swap
    if(nums1[idx]>prev1 && nums2[idx]>prev2)
        ans = solve(nums1,nums2,idx+1,0,dp);
    //swap
    if(nums1[idx]>prev2 && nums2[idx]>prev1)
        ans = min(ans,1+solve(nums1,nums2,idx+1,1,dp));
    
    return dp[idx][isSwap] = ans;
}
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //add -1 at begin of both arr
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool isSwap = 0;
        int n = nums1.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        return solve(nums1,nums2,1,isSwap,dp);
    }
};