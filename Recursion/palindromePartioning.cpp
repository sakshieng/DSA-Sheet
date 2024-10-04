#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
bool isPalin(string &s,int start,int end){
    while(start <= end){
        if(s[start++] != s[end--])
            return 0;
    }
    return 1;
}
void func(int idx,string &s,vector<string>&path,vector<vector<string>>&res){
    if(idx == s.size()){
        res.push_back(path);
        return;
    }
    for(int i=idx;i < s.size();++i){
        if(isPalin(s,idx,i)){
            path.push_back(s.substr(idx,i-idx+1));
            func(i+1,s,path,res);
            path.pop_back();//backtrack
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>res;
        func(0,s,res,ans);
        return ans;
    }
};
//if we are partitioning (0,0) check if that substr is pali or not
