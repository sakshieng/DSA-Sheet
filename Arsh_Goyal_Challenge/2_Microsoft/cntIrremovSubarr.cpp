// https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    bool solve(vector<int> &arr)
    {
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] <= arr[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        // set<int>st;
        // for(auto &i:nums) st.insert(i);
        int cnt = 0;

        // generate all possible subarrays
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                vector<int> temp;
                for (int k = 0; k < i; ++k)
                    temp.push_back(nums[k]);
                for (int k = j + 1; k < n; ++k)
                    temp.push_back(nums[k]);
                if (solve(temp))
                    ++cnt;
            }
        }
        return cnt;
    }
};