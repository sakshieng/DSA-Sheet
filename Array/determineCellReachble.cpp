//https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/
#include<bits/stdc++.h>
//manhanttan;s distance

using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
       if(sx==fx && sy==fy){
           if(t==1) return 0;
           return 1;
       }
        int dis = max(abs(sx - fx) , abs(sy - fy));
        if(dis <= t) return 1;
        return 0;
    }
};