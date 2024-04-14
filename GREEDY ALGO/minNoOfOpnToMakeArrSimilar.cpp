#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/description/

class Solution
{
public:
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        // divide nums and target into even odd
        vector<int> even, odd, evenTarget, oddTarget;
        for (auto &i : nums)
            (i % 2 == 0) ? even.push_back(i) : odd.push_back(i);
        for (auto &i : target)
            (i % 2 == 0) ? evenTarget.push_back(i) : oddTarget.push_back(i);
        // sort all
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        sort(evenTarget.begin(), evenTarget.end());
        sort(oddTarget.begin(), oddTarget.end());

        // greedy the smallest value of nums should map to smallest of target
        long long int increOpn = 0, decreOpn = 0;

        for (int i = 0; i < even.size(); ++i)
        {
            int diff = evenTarget[i] - even[i];
            (diff > 0) ? increOpn += diff / 2 : decreOpn += diff / 2;
        }

        for (int i = 0; i < odd.size(); ++i)
        {
            int diff = oddTarget[i] - odd[i];
            (diff > 0) ? increOpn += diff / 2 : decreOpn += diff / 2;
        }
        return decreOpn * -1;
        // return increOpn;
    }
};

/*
we can always make nums equal to target
we have to do +2 or -2 so odd even behaviour of number never changes
*/