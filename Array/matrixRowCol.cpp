#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/?envType=daily-question&envId=2024-07-20
class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = rowSum.size();
        int m = colSum.size();
        int i = 0, j = 0;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        while (i < n && j < m)
        {
            int x = min(rowSum[i], colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
            // we have fill first elmt as min of both rest all be 0
            if (rowSum[i] == 0)
                i++;
            if (colSum[j] == 0)
                j++;
        }
        return ans;
    }
};
