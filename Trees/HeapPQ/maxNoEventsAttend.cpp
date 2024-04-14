#include<bits/stdc++.h>
//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });//sort by start time
        //curr open events
        priority_queue<int,vector<int>,greater<int>>pq;
        int i = 0,res = 0,n = events.size();
        for (int d = 1; d <= 100000; d++)
        {
            while (pq.size() && pq.top() < d)
            {
                pq.pop();
            }
            while (i<n && events[i][0] == d)
            {
                pq.push(events[i++][1]);
            }
            if (pq.size()) {
                pq.pop();
                ++res;//that many events can happen in time
            }
        }
        return res;
    }
};