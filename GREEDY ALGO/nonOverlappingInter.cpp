#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/submissions/982555541/
class Solution {
public:
   static bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    vector<pair<int,int>>v;
    for(int i=0;i<intervals.size();++i) v.emplace_back(make_pair(intervals[i][0],intervals[i][1]));
    sort(v.begin(),v.end(),cmp);//sort acc to finishing time
    int ans = 0;
    int idx = intervals[0][1];
    for(auto i:v){
        if(i.first < idx){
            ans += 1;
            if (i.second < idx) 
                idx = i.second;  
        }
        else 
            idx = i.second;
    }
    return ans-1;
    }
};