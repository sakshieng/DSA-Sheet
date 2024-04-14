// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/solutions/4463216/beats-100-users-c-java-python-javascript-easy-approach-explained/?envType=daily-question&envId=2023-12-21
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0, n = colors.size();
        for (int i = 1; i < n - 1; i++)
        {
            if (colors[i] == colors[i + 1])
            {
                if (neededTime[i] < neededTime[i + 1])
                    ans += neededTime[i];
                else
                    ans += neededTime[i+1],neededTime[i+1]=neededTime[i];
            }
        }
        return ans;
    }
};