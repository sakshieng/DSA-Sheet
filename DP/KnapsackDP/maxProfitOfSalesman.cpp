#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/
// sorting+lower bound
class Solution {
public:
 static bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), compare);

        map<int, int> dp;
        int res = 0;
        for (int i = 0; i < offers.size(); ++i){
            int start = offers[i][0];
            int end = offers[i][1];
            int profit = offers[i][2];
            if(i == 0) dp[end] = profit;
            else{
                auto it = dp.lower_bound(start);
                if(it == dp.begin()){
                    dp[end] = max(dp[end],profit);
                }else{
                    --it;
                    dp[end] = max(dp[end],profit+it->second);
                }
            }
            res = max(res,dp[end]);
            dp[end] = res;
        }
        return res;
    }
};
