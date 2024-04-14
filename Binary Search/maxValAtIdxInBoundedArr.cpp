#include <bits/stdc++.h>
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
using namespace std;
#define ll long long int
class Solution
{
public:
    // tc O(nlogn) sc O(1)
    int maxValue(int n, int index, int maxSum)
    {
        int emptyR = n - index - 1; // nums to the right of elmt
        int emptyL = index;
        int h = maxSum, l = 1;
        ll res = 0;
        while (l <= h)
        {
            int mid = (h - l) / 2 + l; // 1base idx
            ll leftSum = 0, rightSum = 0, elmt = mid - 1;
            if (emptyR <= elmt)
            {
                rightSum = (elmt * (elmt + 1)) / 2 - ((elmt - emptyR + 1)) / 2;
            }
            else
            {
                rightSum = (elmt * (elmt + 1)) / 2 + (emptyR - elmt); // for repeated 1
            }
            if (emptyL <= elmt)
            {
                leftSum = (elmt * (elmt + 1)) / 2 - ((elmt - emptyL + 1)) / 2;
            }
            else
            {
                leftSum = (elmt * (elmt + 1)) / 2 + (emptyL - elmt);
            }
            ll sum = leftSum + mid + rightSum;
            if (sum <= maxSum)
            {
                l = mid + 1;
                res = mid;
            }
            else
            {
                h = mid - 1;
            }
        }
        return res;
    }
};
/*
we are constructing arr as
when we put no. at idx left side consecutively less and right said more
means n=6 idx=2 maxSum=6
0 1 2 3 4 5 6
6 7 6 5 4 3 2<-arr
5 6 4 3 2 1 0<-arr
""""
3 4 3 2 1 1 1
2 3 2 1 1 1 1<-this will be ans arr

by appying BS on maxSUm we will discard range all above 7 and think in lower range


so for checking sum<=maxSum
as idx=2 so elmt=7 for 1st case hence emptyR sum=n*(n+1)/2 and elmtL=n*(n+1)/2
but for ans case as the elmts are repeating elmt=3 sum would be emptyR=for 3,2 & 1 and for remaining 1 it would be emptyR-elmt=6-3=3

*/