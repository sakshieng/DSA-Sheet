// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23
#include<bits/stdc++.h>
//bit manipulation approach also easy
using namespace std;

class Solution {
public:
    bool isValid(string &currStr,string &newStr){
        //the concatenated str should be unique
        unordered_set<char>st;
        for(char ch:newStr){
            if(st.count(ch) > 0)
                return 0;//means not unique
        st.insert(ch);
        //find all permutations
        if(currStr.find(ch) != string::npos)
            return 0;
        }
        return 1;
    }
    void backtrack(vector<string>& arr,string curr,int start,int &maxLen){
        int ap = curr.length();
        maxLen = max(maxLen,ap);
        for (int i = start; i < arr.size(); i++)
        {
            if(!isValid(curr,arr[i]))
                continue;
            backtrack(arr,curr+arr[i],i+1,maxLen);
        }
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        backtrack(arr,"",0,ans);
        return ans;
    }
};