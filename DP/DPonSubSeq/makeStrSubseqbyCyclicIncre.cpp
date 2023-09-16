#include<bits/stdc++.h>
//https://leetcode.com/contest/biweekly-contest-111/problems/make-string-a-subsequence-using-cyclic-increments/
using namespace std;

class Solution {
public:

bool solve(string &s, string &t,int n,int m){
    if(n==0) return 1;
    if(m==0) return 0;//s is over no compare
    //last char match/m=not
    if(s[n-1]==t[m-1]) return solve(s,t,n-1,m-1);
    if(s[n-1] == t[m-1]+1) return solve(s,t,n-1,m-1);
 if(s[n-1] == 'a' && t[m-1] == 'z') return solve(s,t,n-1,m-1);
    return solve(s,t,n,m-1);
}
    
    bool canMakeSubsequence(string s, string t) {
       if(solve(t,s,t.length(),s.length())) return 1;
        return 0;
    }
};