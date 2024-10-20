// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        int leftSum = 0,rightSum = 0,maxSum = 0;
        for (int i = 0; i <= k-1; i++)
        {
            leftSum = leftSum + nums[i];
        }
        maxSum = leftSum;
        int rightIdx = n-1;
        for (int i = k - 1; i >= 0; i--)
        {
            leftSum = leftSum - nums[i];
            rightSum = rightSum + nums[rightIdx];
            rightIdx--;
            maxSum = max(maxSum,leftSum + rightSum); 
        }
        return maxSum;
    }
};