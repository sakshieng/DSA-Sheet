//monotonic stack
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/ 

 class Solution
    {
    public:
        int largestRectangleArea(vector<int> &nums)
        {
            //         area=width*height width is nsr-nsl-1
            //       here we cant use 2 pointer becauz for same height it will give wrong ans
            // push nsr and nsl in stack by creating pair
            int n = nums.size();
            vector<int> nsr;
            vector<int> nsl;
            stack<pair<int, int>> st;
           //func created for nsr 
            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && st.top().first >= nums[i])
                    st.pop();
                if (st.empty())
                    nsr.push_back(n);
                else
                    nsr.push_back(st.top().second);
                st.push({nums[i], i});
            }
            while (!st.empty())
                st.pop();
            reverse(nsr.begin(), nsr.end());
            // func created for nsl
            for (int i = 0; i < n; i++)
            {
                while (!st.empty() && st.top().first >= nums[i])
                    st.pop();
                if (st.empty())
                    nsl.push_back(-1);
                else
                    nsl.push_back(st.top().second);
                st.push({nums[i], i});
            }
            int ans = 0;
            int maxi = 0;
            for (int i = 0; i < n; i++)
            {
                // index of nsr - index of nsl
                int width = nsr[i] - nsl[i] - 1;
                int height = nums[i];
                ans = width * height;
                maxi = max(maxi, ans);
            }
            return maxi;
        }
    };
    