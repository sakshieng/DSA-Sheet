// https://leetcode.com/problems/binary-trees-with-factors/description/?envType=daily-question&envId=2023-10-26
#include<bits/stdc++.h>
//non-leaf node's value = product of values of its children
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;

        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;

            for (int j = 0; j < i; j++) {
//RC = arr[i]/LC
                if (arr[i] % arr[j] == 0 && dp.find(arr[i] / arr[j]) != dp.end()) {
                    dp[arr[i]] += dp[arr[j]] * dp[arr[i] / arr[j]];
                }
            }
        }

        long result = 0;
        for (auto val : dp) {
            result += val.second;
        }

        return result % (int)(1e9 + 7);
    }
};