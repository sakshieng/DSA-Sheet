// https://leetcode.com/problems/matrix-cells-in-distance-order/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    // we need to return coordinates of all cells in the matrix, sorted by their distance
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<vector<int>> res;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                res.push_back({r, c});
            }
        }
    }

private:
    static void sortCells(vector<vector<int>> &cells, int rCenter, int cCenter)
    {
        sort(cells.begin(), cells.end(), [rCenter, cCenter](const vector<int> &a, const vector<int> &b)
            {
                return (abs(a[0] - rCenter) + abs(a[1] - cCenter)) < (abs(b[0] - rCenter) + abs(b[1] - cCenter)); //smallest distance to the largest distance 
            }
        );
    }
};