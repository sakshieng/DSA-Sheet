// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int findSum(unordered_map<int, int>&mp,int x){
        priority_queue<pair<int,int>>pq;
        for(auto &i:mp){
            pq.push({i.second,i.first});
        }
        int sum = 0;
        for (int i = 0; i < x && !pq.empty(); i++)
        {
            auto top = pq.top();
            pq.pop();
            sum += (top.second * top.first);//sum = val*freq
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        //have a window of size k calculate sum freq[elmt]*elmt
        int n = nums.size();
        // Sliding window approach
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; ++i) {
            freq[nums[i]]++;
        }
        //x sum for first window
        ans.push_back(findSum(freq,x));
        for(int i=1;i <= n-k;++i){
            //window of size k
            freq[nums[i-1]]--;
            if(freq[nums[i-1]] == 0)
                freq.erase(freq[nums[i-1]]);
            
            //add new elmt in window
            freq[nums[i+k-1]]++;
            ans.push_back(findSum(freq,x));
        }
        return ans;
    }
};