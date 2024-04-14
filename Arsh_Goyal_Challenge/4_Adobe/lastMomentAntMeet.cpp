#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = INT_MIN;
        for(auto &i:left) ans = max(ans,i);
        for(auto &i:right) ans = max(ans,n-i);
        return ans;
    }
};