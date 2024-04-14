// https://leetcode.com/problems/pascals-triangle-ii/description/?envType=daily-question&envId=2023-10-16
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex+1);
        triangle[0].push_back(1);

        for (int i = 1; i <= rowIndex; ++i) {
            triangle[i].push_back(1);
            vector<int>& prev_row = triangle[i-1];
            vector<int>& curr_row = triangle[i];

            for (int j = 1; j < prev_row.size(); ++j) {
                curr_row.push_back(prev_row[j-1] + prev_row[j]);
            }
            curr_row.push_back(1);
        }

        return triangle[rowIndex];
    }
};
