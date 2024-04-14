#include <bits/stdc++.h> 
using namespace std;
// https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?leftPanelTab=0
 
#include <bits/stdc++.h>
int mod = (int)(1e9 + 7);
int solve(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (num[0] != 0 and num[0] <= tar)
        dp[0][num[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int nontake = dp[ind - 1][sum];
            int take = 0;
            if (num[ind] <= sum)
                take = dp[ind - 1][sum - num[ind]];
            dp[ind][sum] = (nontake + take) % mod;
        }
    }
    return dp[n - 1][tar];
}

/*
s1-s2=d
total-s2-s2=d
s2=total-d/2
numerator even and >0
*/

int countPartitions(int n, int d, vector<int> &arr) {
    //we have to find how many subsets are having s1-s2=target
    int totsum = 0;
    for (auto &x : arr)
    {
        totsum += x;
    }
    if ((totsum - d) < 0 or (totsum - d) % 2)
    {
        return false;
    }
    return solve(arr, (totsum - d) / 2);
}