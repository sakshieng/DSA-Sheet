// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
// prefix sum on 2d arr problem
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;



class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = rows;
        int cols = grid[0].size();
        vector<vector<int>> prefixX(rows, vector<int>(cols, 0));
        vector<vector<int>> prefixY(rows, vector<int>(cols, 0));
        // as we need to include grid[0][0] problem become easy
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i > 0 && j > 0)
                {
                    prefixX[i][j] = prefixX[i][j - 1] + prefixX[i - 1][j] - prefixX[i - 1][j - 1];
                    prefixY[i][j] = prefixY[i][j - 1] + prefixY[i - 1][j] - prefixY[i - 1][j - 1];
                }
                else if (i > 0)
                {
                    prefixX[i][j] = prefixX[i - 1][j];
                    prefixY[i][j] = prefixY[i - 1][j];
                }
                else if (j > 0)
                {
                    prefixX[i][j] = prefixX[i][j - 1];
                    prefixY[i][j] = prefixY[i][j - 1];
                }
                if (grid[i][j] == 'X')
                    prefixX[i][j]++;
                else if (grid[i][j] == 'Y')
                    prefixY[i][j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(prefixX[i][j] > 0 && prefixY[i][j] > 0 && prefixX[i][j] == prefixY[i][j])
                    ans++;
            }
        }
        return ans;
    }
};