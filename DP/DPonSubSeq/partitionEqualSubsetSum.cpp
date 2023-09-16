#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980
// https://leetcode.com/problems/partition-equal-subset-sum/description/
// divide into exactly 2 subsets such that sum1=sum2 totalSum/2 = subset sum
// same problem subset sum equals target

int mod = (int)(1e9 + 7);
int solve(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1,0);
    if (num[0] == 0)
        prev[0] = 2;// 2 cases -pick and not pick
    else
        prev[0] = 1;
    if (num[0] != 0 and num[0] <= tar)
        prev[num[0]] = 1;// 1 case -pick
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(tar+1,0);
        for (int sum = 0; sum <= tar; sum++)
        {
            int nontake = prev[sum];
            int take = 0;
            if (num[ind] <= sum)
                take = prev[sum - num[ind]];
            curr[sum] = (nontake + take) % mod;
        }
        prev = curr;
    }
    return prev[tar];
}
    
int countPartitions(int n, int d, vector<int> &arr)
{
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

/*
s1-s2=d
total-s2-s2=d
s2=total-d/2
numerator even and >0
*/
