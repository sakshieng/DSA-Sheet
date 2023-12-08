#include <bits/stdc++.h> 
using namespace std; 
//https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1

class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        vector<int> result;

    int rows = matrix.size();
    if (rows == 0) {
        return result;
    }
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0)
            for (int j = 0; j < cols; j++) 
                result.push_back(matrix[i][j]);
         else 
            for (int j = cols - 1; j >= 0; j--) 
                result.push_back(matrix[i][j]);
            
    }

    return result;
    }
};
