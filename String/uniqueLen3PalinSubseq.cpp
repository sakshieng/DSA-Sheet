#include<bits/stdc++.h>
//https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2023-11-14
using namespace std;
//For length 3 palindromes first and last character should be same so find no. of distinct characters b/w first and last occurence of a character and that will be the number of distinct 3 size palindromes b/w that type character in the given string so do this for all the presnt characters in the string we will get all the 3 sized palindromes

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int>first(26,1000001),last(26);
        for(int i=0;i<n;++i)              
        {
            first[s[i]-'a'] = min(i,first[s[i]-'a']);
            last[s[i]-'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            unordered_set<char>st;
            for(int j=first[i]+1;j < last[i];++j)
                st.insert(s[j]);
            ans += st.size();
        }
        return ans;
        
    }
};