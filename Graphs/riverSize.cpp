// https://www.algoexpert.io/questions/river-sizes
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;


void dfs(vector<vector<int>>& matrix,int x,int y,int size){
    int n =  matrix.size(),m = matrix[0].size();
    if((x >= 0 && x < n) && (y >= 0 && y < m))
    {
        //river
        if(matrix[i][j] == 1)
        {
            matrix[i][j] = -1;
            size++;
            dfs(matrix,x+1,y,size);
            dfs(matrix,x-1,y,size);
            dfs(matrix,x,y+1,size);
            dfs(matrix,x,y-1,size);
        }
    }
}
vector<int> riverSizes(vector<vector<int>>& matrix) {
    int n =  matrix.size(),m = matrix[0].size();
    vector<int>ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 1)
            {
                int size = 0;
                dfs(matrix,i,j,size);
                ans.push_back(size);
            }
        }
        
    }
    return ans;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<int> result = riverSizes(matrix);
    
    for (int size : result) {
        cout << size << " ";
    }
    
    return 0;
}
