// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
// https://www.codingninjas.com/studio/problems/maximum-sum-rectangle_1082564?leftPanelTab=0
//we have to find submatrix of max sum so will use kadanes in extended format
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  int kadane(vector<int>&a){
      int size = a.size();
      int maxiSoFar = INT_MIN;
      int maxEndHere = 0;
      for(int i=0;i<size;++i){
          maxEndHere = maxEndHere + a[i];
          if(maxiSoFar < maxEndHere)
            maxiSoFar=maxEndHere;
          if(maxEndHere < 0)
            maxEndHere = 0;
      }
      return maxiSoFar;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxSum = INT_MIN;
        for(int start = 0;start < C;++start){
        vector<int>sum(R,0);//Reset sum for each new 'start'
            for(int end=start;end<C;end++){
                for(int row =0;row<R;row++){
                    sum[row] += M[row][end];
                }
                int currMaxi = kadane(sum);
                maxSum = max(currMaxi,maxSum);
            }
        }
        return maxSum;
    }
};

