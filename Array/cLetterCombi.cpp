// https://www.geeksforgeeks.org/problems/c-letters-collection4552/1
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    bool isValid(int i, int j, int n, int m)
    {
        if (i >= 0 && j >= 0 && i < n && j < m)
            return 1;
        return 0;
    }
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // to perform the queries we need to check the taken elmt is satifying valid condns
        int sum, iLeft, jLeft, iRight, jRight;
        vector<int> res;

        for (int i = 0; i < q; i++)
        {
            sum = 0;
            int a = queries[i][0], x = queries[i][1], z = queries[i][2];
            iLeft = x - a;
            jLeft = z - a;
            iRight = x + a;
            jRight = z + a;

            // iterate over rows
            for (int i = iLeft; i <= iRight; ++i)
            {
                if (isValid(i, jLeft, n, m))
                    sum += mat[i][jLeft];

                if (isValid(i, jRight, n, m))
                    sum += mat[i][jRight];
            }

            // iterate over coulmns
            for (int j = jLeft + 1; j < jRight; ++j)
            {
                if (isValid(iLeft, j, n, m))
                    sum += mat[iLeft][j];

                if (isValid(iRight, j, n, m))
                    sum += mat[iRight][j];
            }
            res.push_back(sum);
        }

        return res;
    }
};

