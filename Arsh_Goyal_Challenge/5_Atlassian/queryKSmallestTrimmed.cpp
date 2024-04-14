// https://leetcode.com/problems/query-kth-smallest-trimmed-number/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
//as it has sorting of last unit digit or last 3 digits so first thing that comes to mind is radix sort
//it could be diff so try to use pq
   string trimNumber(string s,int k){
       int n = s.size();
       string ans = "";
       for(int i = n-1; i >= n - k; --i) ans += s[i];
       reverse(ans.begin(),ans.end());
       return ans;
}
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto &i:queries){
            priority_queue<pair<string,int>>pq;//max heap
            for(int j=0;j<nums.size();j++){
                // cout << trimNumber(nums[j],i[1]) << "\n";
                pq.push({trimNumber(nums[j],i[1]),j});//trimming factor is i[1]
                if(pq.size() > i[0])
                    pq.pop();//kth smallest number
            }
            ans.push_back(pq.top().second);
        } 
        return ans;
    }
};