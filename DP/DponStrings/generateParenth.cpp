// https://leetcode.com/problems/generate-parentheses/description/?envType=featured-list&envId=top-microsoft-questions?envType=featured-list&envId=top-microsoft-questions
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
class Solution {
public:
    void findAll(string result, vector<string>& curr, int open, int close, int n) {
        if (result.length() == 2 * n)  {
            curr.push_back(result);
            return;
        }
        if (open < n)
            findAll(result + "(", curr, open + 1, close, n);
        if (close < open)
            findAll(result + ")", curr, open, close + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> curr;
        // Always starts with open
        findAll("(", curr, 1, 0, n);
        return curr;
    }
};
