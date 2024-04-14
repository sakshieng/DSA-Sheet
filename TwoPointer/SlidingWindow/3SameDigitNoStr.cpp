#include<bits/stdc++.h>
//https://leetcode.com/problems/largest-3-same-digit-number-in-string/submissions/1112300812/?envType=daily-question&envId=2023-12-04
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char common;
        int l = 0, r = 0;

        for (int i = 0; i < num.length() - 2; ++i) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                if (common <= num[i]) {
                    l = i;
                    r = i + 2;
                    common = num[i];
                }
            }
        }

        if (common) 
            return num.substr(l, r - l + 1); 
        return "";
    }
};