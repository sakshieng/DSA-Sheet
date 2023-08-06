#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/car-pooling/description/
class Solution {
public:
//TC->O(nlogn) SC->O(M)
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;//min heap
        for(int i=0;i<trips.size();++i){
            heap.push({trips[i][1],trips[i][0]});
            heap.push({trips[i][2],-trips[i][0]});
        }
        int onboard = 0;
        while(!heap.empty()){
            onboard = onboard + heap.top().second;
            heap.pop();
            if(onboard > capacity) return false;
        }
        return true;
    }
};
/*
(1,2) ->capcity 4-2
(5,-2)->2-(-2)
(3,3)->4-3
(7,-3)->1-(-3)
*/