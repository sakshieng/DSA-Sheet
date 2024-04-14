#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/


class Solution {
public:
//states currPos,destination,steps
long long dp[5000][1001];
const int mod = 1e9 + 7;
long long memo(int i,int steps,int destination){
    if(steps == 0){
        if(i == destination)
            return 1;
        else
            return 0;
    }
    if(dp[i+1100][steps] != -1)
        return dp[i+1100][steps];
    long long left = memo(i-1,steps-1,destination)%mod;
    long long right = memo(i+1,steps-1,destination)%mod;
    return dp[i+1100][steps] = (left+right)%mod;
}
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return (memo(startPos,k,endPos))%mod;
    }
};