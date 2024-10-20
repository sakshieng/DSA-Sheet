/*
find length of longest k-subsequnce where sum of subseq is less than or equal to s
N=5, K2, S = 51

arr[6, 4, 3, 2, 17]
o/p = 2
TC = O(N^2/k)
*/

#include<bits/stdc++.h>
using namespace std;
int solve1(vector<int>&arr,int n,int k,int s){
    int maxLen = 0;
    for(int i=0;i<n;++i){
        int currSum = 0,currLen = 0;
        if(currSum <= s){
            currLen++;
            maxLen = max(maxLen,currLen);
        }else{
            break;
        }
    }
    return maxLen;
}
/*
You are given an array A consisting of Nintegers. Let X and Y be two integers such that 1 < X < Y <N now the value of d(X, Y) is calculated from the given rule:

if A[X]A[Y] then d(X, Y) (Y-X) Otherwise d(X,Y)-0

N = 5
A = [3, 4, 3, 4, 3]

-> d(1, 2) = 0 d(1, 3) = (3 - 1) d(1, 4) = 0 d(1, 5) = (5 - 1) d(2, 3) = 0 d(2, 4) = (4 - 2) d(2, 5) = 0 d(3, 4) = 0 d(3, 5) = (5 - 3) d(4, 5) = 0

Now the summation will be 0 + 2 + 0 + 4 + 0 + 2 + 0 + 0 + 2 o = 10

o/p = 10
*/
//there is an approach by map 

//O(N) = TC
long long solve2(int n,vector<int>&a){
    unordered_map<int, vector<int>> mp;
    long long ans = 0;
    for(int i=0;i < n;++i)
        mp[a[i]].push_back(i);
    for(auto &i:mp){
        auto pos = i.second;
        int size = pos.size();
        if(size > 1){
            long long prefixSum = 0;
            for(int j = 1;j < size;++j){
                prefixSum = prefixSum + pos[i];
                sum += (long long) i*pos[i] - prefixSum;
            }
        }
    }
    return ans;
}