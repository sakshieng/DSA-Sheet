#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
// https://leetcode.com/problems/minimum-window-substring/description/
class Solution {
public:
//brute force -> TC = O(n^2 log m)
//optimized approach -> TC = O(n) + O(m)
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int minLen = INT_MAX;
        int startIdx = -1;
        map<char,int>mp;
        int cnt = 0;
        for (int k = 0; k < m; k++)
        {
            mp[t[k]]++;
        }
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (mp.find(s[j]) != mp.end()) // does exists
            {
                if (mp[s[j]] > 0)
                    cnt++;
                mp[s[j]]--;
            }
            while (cnt == m)
            {
                if (minLen > (j - i + 1))
                {
                    minLen = (j - i + 1);
                    startIdx = i;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] > 0) 
                    {
                        cnt--;
                    }
                } 
                i++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startIdx,minLen);
    }
};