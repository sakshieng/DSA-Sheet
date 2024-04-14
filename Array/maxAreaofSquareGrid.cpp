// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        vector<int>h,v;
        for(auto i:hBars)
            h.push_back(i);
        for(auto i:vBars)
            v.push_back(i);
        int maxiV = 1,maxiH = 1;
        int c = 1;
        for (int i = 1; i < h.size(); i++)
        {
            if(h[i] == h[i-1]+1)//means they are consecutive
                c++;
            else
                c = 1;
            maxiH = max(maxiH,c);
        }
        c = 1;
        for(int i=1;i < v.size();++i){
            if(v[i] == v[i-1])
                c++;
            else
                c = 1;
            maxiV = max(maxiV,c);
        }
        int x = min(maxiV+1,maxiH+1);
        return x*x;
    }
};