/*
backtracking tree
2 ways
    | | | 
    a b c
3 ways
|||  |||   |||
def  def    def
o/p would be ad ae af bd 
TC O(n.4^n)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> res;

    void backtrack(string digits, int i, string currStr) {
        unordered_map<char, string> digitToChar {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "qprs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        if (currStr.length() == digits.length()) {
            res.push_back(currStr);
            return;
        }

        for (char c : digitToChar[digits[i]]) {
            backtrack(digits, i + 1, currStr + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (!digits.empty()) {
            backtrack(digits, 0, "");
        }

        return res;
    }
};

int main() {
    Solution solution;
    string digits = "23"; // Replace "23" with your input digits
    vector<string> result = solution.letterCombinations(digits);
    for (string combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}
