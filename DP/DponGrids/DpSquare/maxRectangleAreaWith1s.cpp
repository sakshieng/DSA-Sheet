#include<bits/stdc++.h>
//https://leetcode.com/problems/maximal-rectangle/description/

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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int>height(m,0);//will carry all the coulmns
        //go across all the rows
        for(int i=0;i < n;++i){
            for(int j=0;j < m;++j){
                if(matrix[i][j] == '1')
                    height[j]++;//we are memoizing i.e.e remebering past heights
                else
                    height[j] = 0;
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea , area);
        }
        return maxArea;
    }
};
//tc O(n*(m+n)) sc O(n) stck+vector