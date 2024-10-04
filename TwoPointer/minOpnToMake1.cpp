// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(),cntOne = 0;
        for (auto &&i : nums)
        {
            if(i == 1) cntOne++;
        }
        if(cntOne > 0)
            return n-cntOne;
        //if we have 1 in arr opn = n - count(1) gcd of consecutive no is 1 
        int minSubArr = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int currSubArrGCD = nums[i];
            for(int j=i+1;j < n;++j){
                currSubArrGCD = __gcd(currSubArrGCD,nums[j]);
                if(currSubArrGCD == 1){
                    minSubArr = min(minSubArr,j-i+1);
                    break;
                }
            }
        }
        return minSubArr == INT_MAX ? -1 : minSubArr + n -1;
    }
};