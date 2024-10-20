#include <bits/stdc++.h>
// sakshi codes here
using namespace std;
//lexo smallest rightmost char delete kra 
//https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/
class Solution
{
public:
    string clearStars(string s)
    {
        // min heap(store char+idx) for lexo small and -1*idx for rightmost elmt as aba* if ba then lexo higher than ab so delete 2nd a
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        vector<bool>deleted;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                if (!pq.empty())
                {
                    auto it = pq.top();
                    pq.pop();
                    deleted[-1*it.second] = true;
                }
            }
            else
                pq.push({s[i], -1 * i});
        }
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*' && !deleted[i])
                res += s[i];

        }
        return res;
    }

};