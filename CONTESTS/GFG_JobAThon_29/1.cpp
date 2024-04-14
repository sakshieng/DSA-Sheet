// https://practice.geeksforgeeks.org/contest/job-a-thon-29-hiring-challenge/problems
#include<bits/stdc++.h>
//maximum money
//editorial soln 
using namespace std;

class Solution {
  public:
  //tc O(1) sc O(1)
    int MaxMoney(int M, vector<int> &B, vector<int> &A) {
        // code here
        int ans = M;
        ans = max(ans,M/B[0]*A[0]+M%B[0]);
        ans = max(ans,M/B[1]*A[1]+M%B[1]);
        ans = max(ans,M/B[2]*A[2]+M%B[2]);
        return ans;
    }
};