// https://leetcode.com/problems/xor-queries-of-a-subarray/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> pref(n + 1, 0); // prefix arr for calculating xor of segment
        for (int i = 0; i < n; ++i)
        {
            pref[i + 1] = pref[i] ^ arr[i];
        }
        vector<int> res;
        for (auto &q : queries)
        {
            res.push_back(pref[q[0]] ^ pref[q[1] + 1]);
        }
        return res; // basically q[0] = left and q[1] = right i.e. pref[right+1]^pref[left]
    }
};