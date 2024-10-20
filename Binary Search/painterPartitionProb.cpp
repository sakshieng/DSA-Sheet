// https://leetcode.com/problems/split-array-largest-sum/description/
// https://www.naukri.com/code360/problems/largest-subarray-sum-minimized_7461751?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?interviewProblemRedirection=true
// https : // www.naukri.com/code360/problems/allocate-books_1090540
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    // minimizing the maximum sum of split the split has to be contiguous
    bool isPossible(vector<int> &pages, int n, int m, int numPages)
    // m splits
    {
        int cntStudents = 1;
        int curSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (pages[i] > numPages)
            {
                return false;
            }
            if (curSum + pages[i] > numPages)
            {
                cntStudents += 1;
                curSum = pages[i];
                if (cntStudents > m)
                {
                    return false;
                }
            }
            else
            {
                curSum += pages[i];
            }
        }
        return true;
    }

    int allocateBooks(vector<int> &arr, int n, int m)
    {
        long long low = 0, high = 1e9;
        long long res = INT_MAX;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, n, m, mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return m > n ? -1 : res;//splits cant be more than size of arr
    }
};