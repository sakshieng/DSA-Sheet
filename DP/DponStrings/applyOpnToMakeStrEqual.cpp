#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//https://codeforces.com/contest/1733/problem/D2
// https://leetcode.com/problems/apply-operations-to-make-two-strings-equal/description/
//https://leetcode.com/contest/weekly-contest-366/
class Solution {
public:
//all diff char wale idx chi len jr odd asel tr we cant flip and make them equal so retrun -1
//2 changing states
int memo(int i,int j,int n,vector<int>&diffIdx,int x,vector<vector<int>>&dp){
    if(i>=n || j<0 || i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    //we are fliping in pair so +2 ne janar
    int pick1 = (diffIdx[i+1]-diffIdx[i]) + memo(i+2,j,n,diffIdx,x,dp);//picking adj elmts at cost=1 from beginning
    int pick2 = (diffIdx[j]-diffIdx[j-1]) + memo(i,j-2,n,diffIdx,x,dp);//picking adj elmts at cost= 1at end 
    int pick3 = x + memo(i+1,j-1,n,diffIdx,x,dp);//picking up one from begining & one from last

    //no case of middle pick it would increase cost
    return dp[i][j] = min({pick1,pick2,pick3});
}
    int minOperations(string s1, string s2, int x) {
        vector<vector<int>>dp(501,vector<int>(501,-1));
        vector<int>diffIdx;
        for (int i = 0; i < s1.length(); i++)
            if(s1[i] != s2[i])
                diffIdx.push_back(i);
        if(diffIdx.size()%2 != 0)
            return -1;
        int n = diffIdx.size();

        return memo(0,n-1,n,diffIdx,x,dp);
    }
};