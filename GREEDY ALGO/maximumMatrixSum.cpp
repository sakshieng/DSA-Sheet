// https://leetcode.com/problems/maximum-matrix-sum/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool neg = 0;
        long long sum = 0;
        int mini = INT_MAX;
     for (int i=0; i<matrix.size(); i++){
            for (int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] < 0)
                    neg = !neg;
                sum += abs(matrix[i][j]);
                // if (abs(matrix[i][j]) <mini)mini= abs(matrix[i][j]);
               mini = min(mini,abs(matrix[i][j]));
            }
        }
        if(neg != 0)
            sum -= (2*mini);//1 time minus kela karan toh sum cha part nasnar 2nd time minus kela karan toh negative asnar
        return sum;
    }
};