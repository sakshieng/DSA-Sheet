#include<bits/stdc++.h>
//https://leetcode.com/problems/maximum-length-of-pair-chain/description/
using namespace std;

class Solution {
public:
        //greedy sort arr wrt to 2nd elmt while traversing check valid next pair & update prev acc
    static bool compare(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        sort(pairs.begin(),pairs.end(),compare);
        int cnt=0,prev=INT_MIN;
        for(int i=0;i<n;++i){
            if(pairs[i][0] > prev){
                cnt++;
                prev = pairs[i][1];
            }
        }
        return cnt;
    }
};