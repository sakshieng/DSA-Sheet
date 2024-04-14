// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (int i = 0; i < arr1.size(); i++)
        {
            bool flg = 1;
            for (int j = 0; j < arr2.size(); j++)
            {
                if (abs(arr1[i] - arr2[j]) <= d)
                {
                    flg = 0;
                    break;
                }
            }
            if(flg == 1)
                cnt++;
        }
        return cnt;
    }
};