#include <bits/stdc++.h>
//https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/?envType=daily-question&envId=2023-11-28
using namespace std;

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        int cnt = 0, n = 0, temp = 0, ans = 1;
        for (auto &it : corridor)
            if (it == 'S')
                n++; // no of plants
        if ((n & 1) || n == 0)
            return 0; // odd plants no partition
        for (auto &it : corridor)
        {
            if (it == 'S')
                cnt++, n--;
            if (cnt == 2 && it == 'P')
                temp++;
            if (cnt == 3)
            {
                if (n)
                    ans = (1ll * ans * (temp + 1)) % 1000000007;
                temp = 0, cnt = 1;
            }
        }
        return ans;
    }
};