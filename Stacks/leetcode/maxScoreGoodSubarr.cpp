//similar approach of largest rec in historgram
//https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/?envType=daily-question&envId=2023-10-22
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

#define ll long long int
class Solution {
public:
vector<int>NSL(vector<int>& a){
    int n = a.size();
    vector<int> ans;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop(); 
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
vector<int>NSR(vector<int>& a){
    int n = a.size();
    vector<int> ans;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.top()]>=a[i]) st.pop(); 
        if(st.empty()) ans.push_back(n);
        else ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
    int maximumScore(vector<int>& nums, int k) {
        vector<int>nsl = NSL(nums);
        vector<int>nsr = NSR(nums);
        reverse(nsr.begin(),nsr.end());
        //just multiply 2 arr
        int score = 0;
        for(int i=0;i<nums.size();++i){
            int l = nsl[i];
            int r = nsr[i];
            if(l<k && r>k)
                //then only update score
                score = max(score,nums[i]*(r-l-1));
        }
        return score;
    }
};