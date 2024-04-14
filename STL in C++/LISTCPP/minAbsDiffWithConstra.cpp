#include<bits/stdc++.h>
using namespace std;

// 2817. Minimum Absolute Difference Between Elements With Constraint
// https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        set<int>st;
        for(int i=x;i<nums.size();++i){
            //insert i-x elmts in set
            st.insert(nums[i-x]);
            //find next greater elmt in set
            auto it = st.upper_bound(nums[i]);
            //find diff with greater elmt
            if(it != st.end()) ans = min(ans,*it-nums[i]);
            //find diff with <= elmt
            if(it != st.begin()) ans = min(ans,nums[i]-*prev(it));  
        }
        return ans;
    }
};
/*
We need to find two ele with atleast dist of x
So for first element me kuthe shidnar ? 0+x = x
Mhnun for loop x pasun ahe, adhich dont matter for search space
For second element?
1+x
For ith element?
i+x
Now apan ky kela x to n sagle insert kela set madhe
Ani ith element sathi i+x nanter search kela using upperbound in set
*/