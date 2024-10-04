#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/jump-game/description/
class Solution
{
public:
    // memo mdhe jevdhe variable tevdhya idx cha DP
    bool memo(vector<int> &nums, int idx, vector<int> &dp)
    {
        bool ans = false;

        if (idx >= nums.size() - 1)
            return true;

        // for 1st case 2 sathi 2 cases yenar apn 3 ani 1 janar so or use kryche ek jri condn asel ki array chya baher gela tr true return kra
        if (dp[idx] != -1)
            return dp[idx];
        for (int i = 1; i <= nums[idx]; ++i)
        {
            ans = ans || memo(nums, idx + i, dp);
            if (ans == true)
                break;
        }
        return dp[idx] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        vector<int> dp;
        dp.resize(nums.size(), -1);
        return memo(nums, 0, dp);
    }

    

};