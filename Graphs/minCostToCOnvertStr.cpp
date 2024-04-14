#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/
using namespace std;

#define ll long long
class Solution {
public:
//Floyd Warshall's algo to precompute all results
//TC O(n) SC O(1)
    const ll inf = 1e18;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>dp(26,vector<ll>(26,inf));
        int n = original.size();

        for(int i=0;i<26;++i)//set transformation cost of each char to 0
            dp[i][i] = 0;

        for (int i = 0; i < n; i++)
            dp[original[i]- 'a'][changed[i]-'a'] = min(dp[original[i]- 'a'][changed[i]-'a'],1LL*cost[i]);

        //to find minimum cost
        for(int k=0;k < 26;++k)
            for(int i=0;i < 26;++i)
                for(int j=0;j < 26;++j)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);

        ll ans = 0;
        for (int i = 0; i < source.length(); i++)
        {
            ans += dp[source[i]-'a'][target[i]-'a'];
            if(ans >= inf)
                return -1;
        }
        return ans;
    }
};