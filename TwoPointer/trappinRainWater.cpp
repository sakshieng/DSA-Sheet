// https://leetcode.com/problems/trapping-rain-water/description/
//keep l r to see how much water we can hold
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int leftMax = height[0],rightMax = height[j];
        int ans = 0;
        while (i < j)
        {
            if(leftMax < rightMax){
                sum += (leftMax - height[i]);
                i++;
                leftMax = max(leftMax,height[i]);
            }else{
                sum += (rightMax - height[j]);
                j--;
                rightMax = max(rightMax,height[j]);
            }
        }
        return ans;
    }
};