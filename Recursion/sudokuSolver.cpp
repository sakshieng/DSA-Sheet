#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
bool isValid(vector<vector<char>>& board,int row,int col,char c){
    //check for every row/col
    for(int i=0;i<9;++i){
        if(board[i][col] == c || board[row][i] == c) return 0;
        //check fo submatrix 3*3 rec under 9*9 
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c) return 0;
    }
    return 1;
}
bool solve(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;
            if (solve(board))
              return 1;
            else
              board[i][j] = '.';//the one u filled up u have to remove it 
          }
        }
        return 0;
      }
    }
  }
  return 1;//there are no empty cells i am not under 2 for loops means everything filled
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
