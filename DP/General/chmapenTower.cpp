
#include<bits/stdc++.h>
//https://leetcode.com/problems/champagne-tower/?envType=daily-question&envId=2023-09-24
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>res((double)query_row+2.0,vector<double>((double)query_glass+2.0,0));
        res[0][0] = (double)poured;
        for(int r=0;r <= query_row;++r){
            for(int c=0;c <= query_glass;++c){
                double temp = (res[r][c]-1.0)/2;//remaining val that need to distribute among bottom r
                if(temp > 0){
                    res[r+1][c] += temp;
                    res[r+1][c+1] += temp;
                }
            }
        }
        return min(1.0,res[query_row][query_glass]);
    }
};