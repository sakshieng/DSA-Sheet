// https://leetcode.com/problems/merge-intervals/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (const vector<int>& interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                // No overlap, add interval directly
                ans.push_back(interval);
            } else {
                // Overlap, merge intervals
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};