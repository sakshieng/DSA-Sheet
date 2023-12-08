#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2023-12-03
//similar to LC:2849
using namespace std;

class Solution {
public:
//Chebyshev distance
    int solve(vector<int>&a,vector<int>&b){
//check whether a to b is reachable or not
        int xDiff = abs(a[0]-b[0]);
        int yDiff = abs(a[1]-b[1]);
        return max(xDiff,yDiff);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int time = 0;
        for(int i=1;i<p.size();++i)
            time += solve(p[i-1],p[i]);
        return time;
    }
};
