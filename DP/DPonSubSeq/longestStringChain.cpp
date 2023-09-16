// u cant following order u can pick any elmts from arr
// https://leetcode.com/problems/longest-string-chain/

#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
static bool comp(string &s1,string &s2){
    return s1.size() < s2.size();
}
bool checkPossible(string &s1,string &s2){
    //here s1>s2 bcda & bcd 
    if(s1.size() != s2.size()+1) return 0;
    //keep pointers to str
    int first = 0,second =0;
    //check till bigger str gets exhausted
    while(first < s1.size()){
        if(s1[first]==s2[second]){
            first++;
            second++;
        }else //if(second < s2.size() && s1[first]==s2[second])
            first++;
    }
    //if both reaches at end simultaneously
    if(first == s1.size() && second == s2.size()) return 1;
    return 0;
}
    int longestStrChain(vector<string>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end(),comp);
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=0;i<n;++i){
            for(int prev=0;prev<i;++prev){
                if(checkPossible(nums[i],nums[prev]) && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                }
            }
            if(dp[i] > maxi) 
                maxi = dp[i];
        }
        return maxi;
    }
};
/*
this is not for subseq its for sequnce
means ['xbc','bc','pxbc','cxbc','cpxbc'] so longest str would be 5 
it is a subset means sort acc to len it like longest divisble subset que
tc->n^2*len of str
*/