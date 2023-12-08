// https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2023-11-26
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// we are allowed to rearrange coulmns of matrix
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (matrix[row][col] != 0 && row > 0)
                    matrix[row][col] += matrix[row-1][col];
            }
            vector<int> currRow = matrix[row]; // currRow[i]->height  i+1->base
            sort(begin(currRow),end(currRow),greater<int>());//descending order
            for (int i = 0; i < n; i++)
                ans = max(ans,currRow[i]*(i+1));//update ans if it is larger
        }
        return ans;
    }
};