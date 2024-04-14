#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1
// https://leetcode.com/problems/distinct-subsequences-ii/description/
//checkout leetcode easy soln is there
//last line for result in that soln is for assuring the final result is +ve
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.length();
        vector<int>dp(n,0);
        vector<int>last(26,-1);  //0-->a  1-->b  25-->z
        const int mod = 1e9+7;
        dp[0] = 2;//empty subseq + char at 0th idx
        last[s[0]-'a'] = 0;
        for(int i=1;i<n;++i){
            dp[i] = 2*dp[i-1];
            dp[i] %= mod;
            if(last[s[i]-'a'] == 0){
                dp[i]--;
                dp[i] %= mod;
            }
            if(last[s[i]-'a']>0){
                dp[i] -= dp[last[s[i]-'a']-1];
                dp[i] %= mod;
            }
            last[s[i]-'a'] = i;
        }
        dp[n-1]--;
        dp[n-1] %= mod;
        if(dp[n-1] < 0) dp[n-1] += mod;
        return dp[n-1];
    }
};
/*
brute force -> make all str and count possi subseq in it
subarray->continuous block of memory subseq->no continuous
TC->O(n) SC->O(n+26)
*/

        
        