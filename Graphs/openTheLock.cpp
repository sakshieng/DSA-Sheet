#include<bits/stdc++.h>
//https://leetcode.com/problems/open-the-lock/
using namespace std;

class Solution {
public:
//without reaching to deadend we have to open the lock
    int openLock(vector<string>& deadends, string target) {
       unordered_set<string> st(begin(deadends), end(deadends));
       //start is deadend 
       if(st.count("0000") != 0) 
            return -1;
        queue<string>q;
        q.push("0000");
        unordered_set<string>visited;//all unique val
        visited.insert("0000");
        int moves = 0;
        //bfs
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string s = q.front();
                q.pop();
                if(s == target)
                    return moves;//termination codn
                for (int k = 0; k < s.length(); k++)
                {
                    string curr = s;//we are manipulating string so store it in tmp var
                    
                    // avoiding those strings which are present in deadends or already visited
                    char c = curr[k];
                    curr[k] = (c == '0' ? '9' : c-1);//rotation down
                    if(st.count(curr) == 0 and visited.count(curr) == 0){
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[k] = (c == '9' ? '0' : c+1);//rotating up
                    if(st.count(curr) == 0 and visited.count(curr) == 0){
                        visited.insert(curr);
                        q.push(curr);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};