#include <bits/stdc++.h>
// https://leetcode.com/problems/word-ladder-ii/
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            // erase all words that has been used in previous level
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                    st.erase(it);
                usedOnLevel.clear();
            }
            string word = vec.back(); // last guy in sequence
            if(word == endWord){
                //the first sequence we reached end means if(ans.size() == 0)
                ans.push_back(vec);
            }
            for (int i = 0; i < word.size(); ++i)
            {
                char original = word[i];
                for(char c = 'a';c<='z';++c){
                    word[i] = c;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        //mark as visited on level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};