#include<bits/stdc++.h>
//https://leetcode.com/problems/wiggle-sort-ii/
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //easy insert in pq
        priority_queue<int>pq;
        for(auto &it:nums)
            pq.push(it);
        for (int i = 1; i <= nums.size(); i+=2)
        {
            nums[i] = pq.top();
            pq.pop();
        }
        for (int i = 2; i <= nums.size(); i+=2)
        {
            nums[i] = pq.top();
            pq.pop();
        }
    }
};