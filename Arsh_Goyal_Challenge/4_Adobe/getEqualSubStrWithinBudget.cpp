// https://leetcode.com/problems/get-equal-substrings-within-budget/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = 0,cost = 0,j = 0;
        for(int i=0;i<s.size();++i){
            cost += abs(s[i]-t[i]);
            while(cost>maxCost){
                cost -= abs(s[j]-t[j]);
                j++;
            }
            len = max(len,i-j+1);
        }
        return len;//we want to return how much len can be converted within cost
    }
};
/*
abcd
bcdf
maxi = max(maxi,i-j+1)
cost 0 set it would be diff of both
jo prynt cost mothi j increase

*/