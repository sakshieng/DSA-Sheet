#include <bits/stdc++.h>
// https://leetcode.com/problems/find-and-replace-pattern/
using namespace std;

class Solution
{
public:
    bool matches(const string &word, const string &pattern)
    {
        char patternCheck[26] = {0}, wordCheck[26] = {0};
        for (int i = 0; i < word.length(); i++)
        {
            char w = word[i], p = pattern[i];
            if (patternCheck[p - 'a'] == 0)
                patternCheck[p - 'a'] = w;
            if (wordCheck[w - 'a'] == 0)
                wordCheck[w - 'a'] = p;
            if (wordCheck[w - 'a'] != p or patternCheck[p - 'a'] != w)
                return 0;
        }
        return 1;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (matches(words[i], pattern))
                ans.push_back(words[i]);
        }
        return ans;
    }
};