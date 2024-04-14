#include<bits/stdc++.h>
//https://leetcode.com/problems/count-number-of-nice-subarrays/
using namespace std;

class Solution {
public:
//subarr which has k odd number is nice
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>oddCntPrefix(n+1,0);
        oddCntPrefix[0] = 1;
        int cnt = 0,oddCnt = 0;
        for (int i = 0; i < n; i++)
        {
            oddCnt += nums[i] % 2;
            if(oddCnt >= k)
                cnt += oddCntPrefix[oddCnt-k];
            oddCntPrefix[oddCnt]++;
        }
        return cnt;
    }
};