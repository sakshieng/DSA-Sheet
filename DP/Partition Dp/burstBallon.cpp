
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/burst-balloons/
//  https://www.codingninjas.com/studio/problems/mining-diamonds_4244494?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

/*
sum of coins would be maximum
its like MCM we are taking sequnce in which ballons can be burst
b1 b2 b3 b4 b5 b6 if we are bursting b4 we cant independtly solve b1 b2 b3 and b5 b6
so for problems to solved in independent way we have to go in reverse dirn
->8 1*8*1 starts from this
->3 8 1*3*8
->3 5 8 3*5*8
->3 1 5 8 3*1*5
total cost would be sum of all
means we are deciding who is the last guy to burst 8 will be last guy to burst out
*/

class Solution
{
public:
    /*
    for recursion
    tc O(n^3) sc O(n^2)+O(n)=depth of recursion tree=auxilary sstack space
    */
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int maxi = INT_MIN;
        for (int idx = i; idx <= j; ++idx)
        {
            int cost = nums[i - 1] * nums[idx] * nums[j + 1] + f(i, idx - 1, nums, dp) + f(idx + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(1, n, nums, dp);
    }
};