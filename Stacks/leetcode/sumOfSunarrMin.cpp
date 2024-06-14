#include <bits/stdc++.h>
//https://leetcode.com/problems/sum-of-subarray-minimums/description/
//diff question do visit 
//https://www.naukri.com/code360/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047
using namespace std;

class Solution {
public:
    const int mod=1e9+7;
    int sumSubarrayMins(vector<int> &arr)
    {
        int len = arr.size();
        long long ans = 0;
        vector<int>left(len,-1);
        vector<int>right(len,len);
        stack<int>st;
        //less elmt for each idx
        for (int i = 0; i < len; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i]) 
            {
                st.pop();
            }
            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = len-1; i >= 0; i--)
        {
            
            while (!st.empty() && arr[st.top()] > arr[i]) 
            {
                st.pop();
            }
            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }
        for (int i = 0; i < len; i++)
        {
            long long left_dist = i - left[i];
            long long right_dist = right[i] - i;
            long long product = left_dist * right_dist % mod * arr[i] % mod;
            ans = (ans + product) % mod;
        }
        return static_cast<int>(ans);
    }
    long long sumOfMaxAndMin(vector<int>&arr,int len, int k){
        multiset<int>st;
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            st.insert(arr[i]);//tevhdya ch len che elmts insert kra
        }
        int mini = *(st.begin());
        int maxi = *(st.rbegin());
        ans += (mini + maxi);
        //start idx of prev window
        int startIdx = 0;
        for (int i = k; i < len; i++)
        {
            st.erase(st.find(arr[startIdx]));
            st.insert(arr[i]);
            mini = *(st.begin());
            maxi = *(st.rbegin());
            ans += (mini + maxi);
            startIdx++;
        }
        
        return ans;
    }
};