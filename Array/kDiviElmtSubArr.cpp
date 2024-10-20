#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/k-divisible-elements-subarrays/
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
       //TC O(N^2)
    //generate all possible subarr
    set<vector<int>>st;//to avoid duplication
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;
        vector<int>a;
        for (int j = i; j < nums.size(); j++)
        {
            a.push_back(nums[j]);
            if(nums[j]%p == 0)
            {
                cnt++;
            }
            if(cnt > k)
                break;
            st.insert(a);
        }
        
    }
    // for (const auto& vec : st) {
    //     cout << "{ ";
    //     for (const auto& elem : vec) {
    //         cout << elem << " ";
    //     }
    //     cout << "}" << endl;
    // }
    return st.size(); 
    }
};