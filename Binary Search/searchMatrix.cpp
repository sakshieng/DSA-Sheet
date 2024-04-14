// https://leetcode.com/problems/search-a-2d-matrix/
// https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
// https://www.hackerrank.com/code-it-contest-22-1
// search element in sorted matrix
// TC-->n(log n to the base 2)
#include <bits/stdc++.h>
/* Sakshi */
using namespace std;

int main()
{
//  i=0 first row j=n-1 last column
// i might exceed row number in downward dirn
// j might get smaller than zero as we are moving left
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        //         low index for the imaginary mid index is [mid/m][mid%m]
        if (matrix.size() == 0)
            return false;
        int n = matrix.size();
        //       size of row
        int m = matrix[0].size();
        //       size of coulmn
        int lo = 0;
        int hi = (n * m) - 1;
        while (lo - hi < 1)
        {
            int mid = lo + (hi - lo) / 2;
            // index / numberOfCols => which row
            // index % numberOfCols => which col
            /* mat[x][y]-> arr[x*n+y]*/
            if (matrix[mid / m][mid % m] == target)
            {
                return true;
            }
            if (matrix[mid / m][mid % m] < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return false;
    }
};
    return 0;
 }
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
   class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
			// target is smaller than current element so it can be in this row, so move to previous column 
            else if(matrix[i][j] > target){ 
                j--;
            }
			// target is greater than current element so it cannot be in this row, so move to next row
            else{
                i++;
            }
        }
        return false;
    }
};
   return 0;
}
*/