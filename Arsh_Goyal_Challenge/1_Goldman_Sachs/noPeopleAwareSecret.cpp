#include <bits/stdc++.h>
//https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/
using namespace std;

#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;
    int dp[1001];
    long long memo(int i, int delay, int forget, int n)
    {
        int whenWillStart = i + delay;
        int whenWillForget = i + forget;
        if (dp[i] != -1)
            return dp[i];
        int ans = (whenWillForget>n);//when condn true ans=1 o.w. ans=0
        for (int j = whenWillStart; j < min(whenWillForget, n + 1); ++j)
            // person can remember secret upto max (n+1)th day
            ans = (ans + (memo(j, delay, forget, n)) % mod) % mod;
        return dp[i] = ans%mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        if(delay == forget)
            return 1;
        memset(dp,-1,sizeof(dp));
        return memo(1,delay,forget,n);//1st day hence i = 1
    }
};