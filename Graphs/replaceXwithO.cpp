#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
class Solution{
private:
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat,int delRow[],int delCol[]){
    vis[row][col] = 1;//mark it visited
    
    int n = mat.size();
    int m = mat[0].size();
    
    //check for top,right,bottom,left
    for(int i=0;i<4;i++){
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];
        if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and !vis[newRow][newCol] and mat[newRow][newCol] == 'O'){
            dfs(newRow,newCol,vis,mat,delRow,delCol);
        }
    }
}


public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<int>>vis(n,vector<int>(m,0));
       //travrse 1st row and nth row
       int delRow[] = {-1,0,1,0};
       int delCol[] = {0,1,0,-1};
       
       for(int j=0;j<m;++j){
           //first row
           if(!vis[0][j] and mat[0][j] == 'O'){
               dfs(0,j,vis,mat,delRow,delCol);
           }
           //last row
           if(!vis[n-1][j] and mat[n-1][j] == 'O'){
               dfs(n-1,j,vis,mat,delRow,delCol);
           }
       }
       //traverse 1st col and last col
       for(int i=0;i<n;++i){
           //first col
           if(!vis[i][0] and mat[i][0] == 'O'){
               dfs(i,0,vis,mat,delRow,delCol);
           }
           //last col
           if(!vis[i][m-1] and mat[i][m-1]  =='O'){
               dfs(i,m-1,vis,mat,delRow,delCol);
           }
       }
       
        
       for(int i=0;i<n;++i){
           for(int j=0;j<m;++j){
               //u havent touched anyone at the boundary
               if(!vis[i][j] and mat[i][j]=='O'){
                   mat[i][j] = 'X';
               }
           }
       }
       return mat;
    }
    //TC O(n*m) SC O(n*m)
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}