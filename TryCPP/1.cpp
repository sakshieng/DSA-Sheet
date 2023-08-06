#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
            int n = nums.size();
    int mini = 0;
    
        
        // for(auto i:nums) st.insert(i);
    while (set<int>(nums.begin(), nums.end()).size() > 1) {
        vector<int>ans(n);

        for (int i = 0; i < n; ++i) {
            ans[i] = min(nums[i], min(nums[(i - 1 + n) % n], nums[(i + 1) % n]));
        }

        nums = ans;
        mini++;
    }

    return mini;
    }
};