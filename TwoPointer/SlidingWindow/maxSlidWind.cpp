
#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //TC :O(n)O SC: O(k)
        deque<int>dq;//we need max at every window so store elmt in decre order in queue so max elemt will be at font
        int j = 0,i=0;
        vector<int>ans;
        while(j < nums.size()){
            while(dq.size() > 0 && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1 == k){
                ans.push_back(dq.front());//max
                if(dq.front()==nums[i]) dq.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
    vector<int>wind(vector<int>& nums, int k){
        int n = nums.size();
        vector<int>ans;
        //use pair pq first will track elmt & second track idx of elmt
        priority_queue<pair<int,int>>pq;
        //if elmt is part of window? then its max or else it needs to be popped
        int i=0,j=0;
        while (j < n)
        {
            pq.push({nums[j],j});
            if(j-i+1 == k){
                while (!pq.empty() && pq.top().second < i)
                {
                    //second is toh idx
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++;
            }
            j++;
        }
        return ans;
    }
};
