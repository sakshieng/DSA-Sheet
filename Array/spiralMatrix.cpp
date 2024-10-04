// https://leetcode.com/problems/spiral-matrix/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> snakePattern(vector<vector<int>> matrix)
    {
        int cnt = 0;
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row * col; // no of elemts to be printed

        // intialize index
        int startingRow = 0;     // 123
        int endingRow = row - 1; // 789
        int startingCol = 0;     // 147
        int endingCol = col - 1; // 369

        while (cnt < total)
        {
            // print starting row 123
            for (int idx = startingCol; cnt < total && idx <= endingCol; idx++)
            {
                ans.push_back(matrix[startingRow][idx]);
                cnt++; // elemt add then increase this
            }
            startingRow++;

            // print starting col 369
            for (int idx = startingRow; cnt < total && idx <= endingRow; idx++)
            {
                ans.push_back(matrix[idx][endingCol]);
                cnt++;
            }
            endingCol--;

            // print ending row 987
            for (int idx = endingCol; cnt < total && idx >= startingCol; idx--)
            {
                ans.push_back(matrix[endingRow][idx]);
                cnt++;
            }
            endingRow--;

            // print ending col 741
            for (int idx = endingRow; cnt < total && idx >= startingRow; idx--)
            {
                ans.push_back(matrix[idx][startingCol]);
                cnt++;
            }
            startingCol++;
        }
        return ans;
    }
     
};
