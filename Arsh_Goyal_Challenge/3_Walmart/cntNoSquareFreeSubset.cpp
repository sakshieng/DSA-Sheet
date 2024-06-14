// https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/
#include <bits/stdc++.h>
// go thr this question bitmask dp
//  https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/
using namespace std;

class Solution
{
public:
    // prime factorize the product of subset
vector<int>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; // mask 30 -
    const int mod = 1e9 + 7;
    int dp[1001][1025];
    int memo(vector<int> &nums,int i,int mask){
        if(i == nums.size())
            return 0;
        if(dp[i][mask] != -1)
            return dp[i][mask];
        int nonPick = memo(nums,i+1,mask)%mod;//use mask without updation
        int pick = 1,newMask = mask;
        for (int j = 0; j < 10; ++j)
        {
            if(nums[i] % primes[j] == 0)//num is divisible by prime means it is facotr of produc
            {
                if(mask & (1<<j)){//ith bit set then exit a square of higher power of prime hence not take
                    pick = 0;
                    break;
                }
                newMask |= (1<<j);//bit is unset update mask 
            }
        }
        if(pick == 1)
            pick = (1ll + memo(nums,i+1,newMask))%mod;
        
        return dp[i][mask] = (pick+nonPick)%mod;
    }
    int squareFreeSubsets(vector<int> &nums)
    {
        memset(dp,-1,sizeof(dp));
        //remove the num which are factor of (prime[i])^2
        vector<int>ans;
        for (auto &i : nums)
        {
            bool flg = 1;
            for (int j = 0; j < 10; ++j)
            {
                if (i % (primes[j] * primes[j]) == 0)
                {
                    flg = 0;
                    break;
                }
            }
            if (flg)
                ans.push_back(i);
        }
        return memo(ans,0,0);
    }
};
