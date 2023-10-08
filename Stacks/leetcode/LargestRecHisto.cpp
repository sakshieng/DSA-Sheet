#include<bits/stdc++.h>
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxAns = 0;
        int n = heights.size();
        for(int i=0;i <= n;++i){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int ans = heights[st.top()];//would be equal to heigh
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxAns = max(maxAns,width*ans);
            }
            st.push(i);
        }
        return maxAns;
    }
};