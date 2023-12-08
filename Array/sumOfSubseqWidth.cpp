#include<bits/stdc++.h>
//https://leetcode.com/problems/sum-of-subsequence-widths/
using namespace std;

class Solution {
public:
const int mod = 1e9 + 7;
//order of elmts doesn't matterr as we are choosing all subsequen & take diff of max min 
//3 is min for some subseq and max for some subseq so each num's contribution to seq
//a[i] -> max asnare 2^i seq
//a[i] -> min asnare 2^(n-i-1) seq 
    int sumSubseqWidths(vector<int>& nums) {
      vector<long long>pow(nums.size());
        pow[0] = 1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();++i){
            pow[i] = (pow[i-1]*2)%mod;
        }
        long long ans = 0;
        for(int i=0;i< nums.size();++i){
            ans = ( ans + pow[i]*(nums[i] - nums[nums.size()-i-1])) %mod;
        }
        return ans;
    }
};