//for given digits how many decodes we can generate
#include<bits/stdc++.h>
//https://leetcode.com/problems/decode-ways/
using namespace std;
//for given digits how many decodes we can generate


class Solution {
public:
    int dp[101];
    int help(string &s,int i){
        if(i >= s.size()) 
            return 1;//decoded entire string
        if(dp[i] != -1)
            return dp[i];
        int ans = 0;
        int op1 = s[i] - '0',op2 = 0;
        if(i < s.size()-1){//at least 2 numbers left
            op2 = op1*10 + s[i+1]-'0';//convert to integer
        }
        if(op1 > 0)
            ans += help(s,i+1);
            //like 106 06 cant be decoded as 0&6 or 06 so add this condn
        if(op1 > 0 && op2 > 0 && op2 <= 26)
            ans += help(s,i+2);
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        return help(s,0);
    }
};