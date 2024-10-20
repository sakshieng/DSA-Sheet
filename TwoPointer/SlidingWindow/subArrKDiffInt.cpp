#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        set<int> st;
        // for (auto &&i : nums)
        // {
        //     st.insert(i);
        // }
        int cnt = 0;
        int l = 0, n = nums.size();
        for (int r = 0; r < n; r++)
        {
            st.insert(nums[l]);
            while (st.size() > k)
            {
                st.erase(st.find(nums[r]));
                cnt++;
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

    long long maximumTotalDamage(vector<int> &power)
    {
        long long ans = 0, maxi = 0;
        for (int i = 0; i < power.size(); i++)
        {
            if (power[i] != power[i] - 2 or power[i] == power[i] - 1 or power[i] == power[i] + 1 or power[i] == power[i] + 2)
            {
                ans += power[i];
                maxi = max(ans, maxi);
            }
        }
        return maxi;
    }
    
};