#include<bits/stdc++.h>
// https://leetcode.com/problems/backspace-string-compare/description/
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return getActual(s) == getActual(t);
    }

private:
    string getActual(string input) {
        string actualString;
        int hashCount = 0;

        for (int i = input.size() - 1; i >= 0; i--) {
            // Keep a count of backspace characters
            if (input[i] == '#') {
                hashCount++;
                continue;
            }

            // If backspace count > 0 reduce it and skip char
            if (hashCount > 0) {
                hashCount--;
            } else {
                // If no backspace, just insert at begin
                actualString.insert(actualString.begin(), input[i]);
            }
        }

        return actualString;
    }
};
