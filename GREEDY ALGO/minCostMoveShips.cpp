// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/description/?envType=problem-list-v2&envId=e3hce697
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int even = 0, odd = 0;
        for (int n : position)
        {
            if (n & 1)
                odd++;
            else
                even++;
        }
        // find min cost to make all nums with same parity
    }
};
