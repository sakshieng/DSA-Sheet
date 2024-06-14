#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// /https://leetcode.com/contest/weekly-contest-400/problems/count-days-without-meetings/
//merge interval updated que
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> ans;
        for (const vector<int>& k : meetings) {
            if (ans.empty() || ans.back()[1] < k[0] - 1) {
                // No overlap
                ans.push_back(k);
            } else {
                // Overlap, merge meetings
                ans.back()[1] = max(ans.back()[1], k[1]);
            }
        }

        int cnt = 0;
        int endIdx = 0;

        for (const auto& i : ans) {
            int s = i[0];
            int e = i[1];
            if (s > endIdx + 1) {
                cnt += (s - endIdx - 1);
            }
            endIdx = e;
        }
        if (endIdx < days) {
            cnt += (days - endIdx);
        }

        return cnt;
    }
};