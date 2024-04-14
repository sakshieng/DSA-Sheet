#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int currSum = 0;
        int n = a.size();
        int ans = 0;
        unordered_map<int,int>map;
        
        for(int i=0;i<n;++i){
            currSum += a[i];
            if(currSum-k == 0) ans++;
            //for case 0 to ith idx direct sum found at initial
            if(map.find(currSum-k) != map.end()){
                ans += map[currSum-k];
            }
            map[currSum]++;
        }
        
        return ans; 
    }
};
//map TC O(n) SC O(1) constant space key=currSum value=idx 