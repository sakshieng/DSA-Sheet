#include<bits/stdc++.h>
/* Sakshi */
using namespace std;
// in que we have given matrix of n*n size basically we have to find kth smallest element of matrix
//we will use binary search 
int main()
{
   class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
// hi=highest index element oi=1st element mid=middle yane hi+oi/2
int n=matrix.size();
int hi=matrix[n-1][n-1];
int oi=matrix[0][0];
int mid;
while(hi-oi>=1)
// imp to use equal to
{
    mid=oi+(hi-oi)/2;
    int tot=0;
    for(int i=0;i<n;++i)
    {
        int small=upper_bound(matrix.begin(),matrix.end(),mid)-matrix.begin();
        tot += small;
    }
    if(tot<k)
    return oi=mid+1;
    else
    return hi=mid;
}
    }
};
   return 0;
}