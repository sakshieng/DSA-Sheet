// https://leetcode.com/problems/remove-duplicate-letters/description/
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int n = s.size();
        // we need your
        unordered_map<char, int> mp;
        for (auto &&i : s)
        {
            mp[i]++;
        }
        stack<char> st;
        vector<bool> inStack(26, 0); // to track vis char
        for (auto &&i : s)
        {
            mp[i]--;
            // stack in smallest in lexicographical order
            while (!st.empty() && st.top() > i && mp[st.top()] > 0)
            {
                // mark as not in stack
                inStack[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(i);
            inStack[i - 'a'] = 1;
        }
        string result;
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};