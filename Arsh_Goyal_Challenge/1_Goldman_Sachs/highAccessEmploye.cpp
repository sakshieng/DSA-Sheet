// https://leetcode.com/problems/high-access-employees/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>>mp;
        for(auto &it:access_times){
            int time = stoi(it[1]);
            mp[it[0]].push_back(time);
        }
        //sort each employee access time
        for(auto &it:mp)
            sort(begin(it.second),end(it.second));
        vector<string>ans;
        for(auto &it:mp){
            vector<int>&time = it.second;
            for (int i = 2; i < time.size(); i++)
            {
                if(time[i]-time[i-2] < 100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        return ans;
    }
};