#include<bits/stdc++.h>
//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/submissions/?envType=daily-question&envId=2023-09-11
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>>tmp;
        vector<vector<int>>ans;
        int n = groupSizes.size();
        for(int i=0;i < n;++i){
            int size = groupSizes[i];
            tmp[size].push_back(i);
            if(tmp[size].size() == size){
                ans.push_back(tmp[size]);
                tmp[size].clear();
            }
        }
        return ans;
    }
};
// a hash table allows to store & look up grp sizes & members 
//for each grp size we will have list of members 
//when to form a grp->when tmp list reaches desired grp size u will pop members and form a grp
//tc O(n) sc O(n)