/*
How to understand a DP problem
-->count the total no of distinct ways i.e. try all possible ways we apply recursion

1}Try to represent the problem in terms of index
2}Do all possible stuff on that index acc to problem
3}for all possible ways-->
1-->count all ways
2-->Find maximum/minimum- return the choice/way with maximum/minimum output
*/
// https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// this approach will give TLE for last 2 cases
//  RECURSIVE APPROACH T.C=O(2^n) s.c=O(n)
// #include <bits/stdc++.h>
// int func(int ind)
// {
//     if(ind==0) return 1;
//     if(ind==1) return 1;
//     int left=func(ind-1);
//     int right=func(ind-2);
//     return left+right;
// }
// int countDistinctWays(int nStairs) {
//     //  Write your code here.
//     func(0);
//     return nStairs;
//}

// Memorization approach T.C=O(N),S.C=O(2*N)(if we considering recursive stack space)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

int solve(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return dp[n] = 1;
    if(dp[n] != -1) return dp[n];
    int left = solve(n - 1, dp);
    int right = solve(n - 2, dp);
    int ans = (left + right);
    return dp[n] = ans;
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

int main() {
    Solution solution;
    int n = 4;
    int result = solution.climbStairs(n);
    cout << "Number of distinct ways: " << result << endl;

    return 0;
}