#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-penalty-for-a-shop/description/
using namespace std;

class Solution {
public:
    int bestClosingTime(std::string cu) {
        int n = cu.size();
        int cntN = 0, cntY = 0;
        vector<int> prefixN = {0};
        vector<int> suffixY = {0};

        for (char c : cu) {
            cntN += (c == 'N');
            prefixN.push_back(cntN);
        }

        for (auto it = cu.rbegin(); it != cu.rend(); ++it) {
            char c = *it;
            cntY += (c == 'Y');
            suffixY.push_back(cntY);
        }

        reverse(suffixY.begin(), suffixY.end());

        int best_hour, min_penalty = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            int penalty = prefixN[i] + suffixY[i];
            if (penalty < min_penalty) {
                min_penalty = penalty;
                best_hour = i;
            }
        }

        return best_hour;
    }
};
