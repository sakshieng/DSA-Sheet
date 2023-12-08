#include<bits/stdc++.h>
//https://leetcode.com/problems/build-an-array-with-stack-operations/submissions/1090789634/?envType=daily-question&envId=2023-11-03
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        unordered_set<int> st(target.begin(), target.end());
        vector<string> result;

        for (int i = 1; i <= target.back(); ++i) {
            if (st.find(i) != st.end()) {
                result.push_back("Push");
            } else {
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};