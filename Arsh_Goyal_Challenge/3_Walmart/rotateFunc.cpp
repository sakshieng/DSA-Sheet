// https://leetcode.com/problems/rotate-function/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        long int sum = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i]; // sum of original array elements
            res += i * nums[i];
        }
        // rotate kela ki ek ek ne shift honar
        // last elmt n-1 times call hoto
        long int maxi = res;
        for (int i = n - 1; i >= 0; i--)
        {
            res += sum - (nums[i] * n);
            maxi = max(res, maxi);
        }
        return maxi;
    }
};