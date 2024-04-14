// https://leetcode.com/problems/group-anagrams/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // return as 2-d vector of string
        // key prmane sort jhaley
        map<string,vector<string>>m;
        for(string &s:strs)
        {
            string temp=s;//copy has been created of s
            sort(temp.begin(),temp.end());//to get key 
            m[temp].push_back(s);//pushed initial string to map
        }
       vector<vector<string>>ans;
       for(auto &j:m)
       {
           ans.push_back(j.second);
       }
       return ans;
    }
};
/*
store these words in map let it sorted and then store freqn will find anagram
["eat","tea","tan","ate","nat","bat"]
aet:eat tea ate
ant:tan nat
abt:bat
*/