#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//celebrity don't know anyone but everybody know him
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat, int n) 
    {
        int indegree[n] = { 0 }, outdegree[n] = { 0 };
 
        // query for all edges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = mat[i][j];
 
                // set the degrees
                outdegree[i] += x;
                indegree[j] += x;
            }
        }
 
        for (int i = 0; i < n; i++)
            if (indegree[i] == n - 1 && outdegree[i] == 0)
                return i;
 
        return -1;
    }
};