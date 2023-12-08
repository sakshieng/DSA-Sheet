//mutlisource shortest path algo find -ve cycle as well
#include<bits/stdc++.h>
//https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
using namespace std;
//o(n^3) tc O(n^2) sc

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if(i == j) matrix[i][j] = 0;
            }
        }
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
        //if graph has -ve cycle u can say if(matris[i][j] < 0)
        
	}
};
