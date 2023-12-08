#include<bits/stdc++.h>
// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/?envType=daily-question&envId=2023-10-10
using namespace std;

class Solution {
public:
//sort arr & for every index do a binary search to get possible right end of  window and calculate possible answer
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        set<int> s; // to store unique elmts from 'nums'

        for (auto a : nums) {
            s.insert(a);
        }

        vector<int> unique(s.begin(), s.end());

        int j = 0; 
        int m = unique.size();

        for (int i = 0; i < m; i++) {
            //Move 'j' to find rightmost element within curr range
            while (j < m && unique[j] < unique[i] + n) {
                j++;
            }
            // Calculate min oprns required for curr range
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};