// https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int &it:nums) mp[it]++;
    int maxi = 0;
    for(auto &[key,val]:mp){
        int curr = val;
        int k = 2;
        while (mp.count(key*k))
        {
            curr += mp[key*k];
            k *= 2;
        }
        maxi = max(maxi,curr);
    }
    return maxi;
    }
};
