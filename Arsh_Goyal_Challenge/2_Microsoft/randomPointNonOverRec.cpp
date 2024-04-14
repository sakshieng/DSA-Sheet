#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
class Solution {
public:
//area of rec are the no of points we can chose
//binary search
    int n;
    long int arr;
    vector<vector<int>>rec;
    vector<long int>searc;
    Solution(vector<vector<int>>& rects) {
        //intializing object with given recs
        n = rects.size();
        arr = 0;
        for(auto x:rects){
            arr += (x[2]-x[0]+1)*(x[3]-x[1]+1);
            searc.push_back(arr);
        }
        rec = rects;
    }
    
    vector<int> pick() {
        int randomVal = (rand() % arr);
        int ithRectangle = upper_bound(begin(searc),end(searc),randomVal)-begin(searc);

        long int x = rec[ithRectangle][2] - rec[ithRectangle][0] + 1;//no of x points
        long int y = rec[ithRectangle][3] - rec[ithRectangle][1] + 1;//no of y points

// take as per area of rec
        int fx = rec[ithRectangle][0] + (rand() % x);
        int fy = rec[ithRectangle][1] + (rand() % y);

        return {fx,fy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */