// https://leetcode.com/contest/weekly-contest-373/problems/matrix-similarity-after-cyclic-shifts/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans = mat;

        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0) {
                rotate(ans[i].begin(), ans[i].begin() + k % n, ans[i].end());//even
            } else {
                rotate(ans[i].rbegin(), ans[i].rbegin() + k % n, ans[i].rend());//odd
            }
        }

        return mat == ans;
    }
};
