#include <bits/stdc++.h>
//https://leetcode.com/problems/word-search/
using namespace std;

class Solution
{
public:
    bool help(vector<vector<char>> &board, string word, int idx, int r, int c)
    {
        if (idx == word.size())
            return 1;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx])
            return 0;
        char original = board[r][c];
        board[r][c] = '#'; // mark cell visited
        // all dirn
        bool found = help(board, word, idx + 1, r + 1, c) ||
                     help(board, word, idx + 1, r - 1, c) ||
                     help(board, word, idx + 1, r, c + 1) ||
                     help(board, word, idx + 1, r, c - 1);
        board[r][c] = original;
        return found;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (help(board, word, 0, r, c))
                {
                    return 1;
                }
            }
        }

        return 0;
    }
};