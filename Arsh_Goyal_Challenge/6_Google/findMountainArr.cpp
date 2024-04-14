
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/find-in-mountain-array/description/

// binary search
class MountainArray
{
public:
    int get(int index);
    int length();
};
class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int length = mountainArr.length();

        int peakIndex = findPeakIndex(1, length - 2, mountainArr);

        int increaseSlope = binarySearch(0, peakIndex, target, mountainArr, false);
        if (mountainArr.get(increaseSlope) == target)
            return increaseSlope; // Target found in the increasing part.

        int decreasingSlope = binarySearch(peakIndex + 1, length - 1, target, mountainArr, true);
        if (mountainArr.get(decreasingSlope) == target)
            return decreasingSlope;
        return -1;
    }

    int findPeakIndex(int low, int high, MountainArray &mountainArr)
    {
        while (low != high)
        {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int binarySearch(int low, int high, int target, MountainArray &mountainArr, bool reversed)
    {
        while (low != high)
        {
            int mid = low + (high - low) / 2;
            if (reversed)
            {
                if (mountainArr.get(mid) > target)
                    low = mid + 1;
                else
                    high = mid;
            }
            else
            {
                if (mountainArr.get(mid) < target)
                    low = mid + 1;
                else
                    high = mid;
            }
        }
        return low;
    }
};