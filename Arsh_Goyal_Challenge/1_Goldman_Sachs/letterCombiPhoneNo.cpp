// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
    vector<string>ans;
    void solve(string digits,int i,string currStr){
        unordered_map<char, string> mp {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "qprs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        if(currStr.length() == digits.length()){
            ans.push_back(currStr);
            return;
        }
        for(char c:mp[digits[i]])
            solve(digits,i+1,currStr+c);
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.empty())
            solve(digits,0,"");
        return ans;
    }
};