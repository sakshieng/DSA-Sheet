// https://leetcode.com/problems/combination-sum-ii/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int>tmp;
        function<void(int, int)> solve = [&](int currIdx,int currSum){
            if(currSum == 0)
            {
                ans.emplace_back(tmp);
                return;
            }
            if (currIdx >= candidates.size() || currSum < candidates[currIdx]) {
                return;
            }
            for (int j = currIdx; j < candidates.size(); j++)
            {
                if(j > currIdx && candidates[j] == candidates[j-1])
                {
                    continue;
                }
                tmp.emplace_back(candidates[j]);
                solve(j+1,currSum-candidates[j]);
                tmp.pop_back();
            }
        };
        solve(0,target);
        return ans;
    }
};