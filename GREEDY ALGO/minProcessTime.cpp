// https://leetcode.com/problems/minimum-processing-time/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end());
        int n = tasks.size();
        int j = n-1;
        int m = processorTime.size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            while (cnt < 4) //want length of 4 always
            {
                ans = max(ans,processorTime[i]+tasks[j]);
                cnt++;
                j--;
            }
        }
        return ans;
    }
};