#include <bits/stdc++.h>
// https://leetcode.com/problems/reverse-pairs/
// use divide & conquer -> merge sort along with 2-pointer
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums, int s, int m, int e, int &res)
    {
        int l = s, r = m + 1;
        while (l <= m && r <= e)
        { 
            // we are doing for half part so l will go upto m
            if (nums[l] > 2ll * nums[r])
                res += m - l + 1, r++;
            else
                l++;
        }
        sort(nums.begin() + s, nums.begin() + e + 1); // 2 pointer shortcut
    }
    void mergeSort(vector<int> &nums, int s, int e, int &res)
    {
        if (s == e)
            return;
        int m = (s + e) / 2;
        mergeSort(nums, s, m, res);
        mergeSort(nums, m + 1, e, res);
        merge(nums, s, m, e, res);
    }
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        mergeSort(nums, 0, n - 1, ans);
        return ans;
    }
};
/*
we are having log2N levels and doing o(n) opn on each level so TC->nlog2n base 2
3 4 2 1
3 4     2 1
3   4   2   1
check for
3 4     2 1
combine them
1 2 3 4
*/