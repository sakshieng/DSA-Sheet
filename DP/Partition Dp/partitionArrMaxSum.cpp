#include<bits/stdc++.h>
//front partition
// https://leetcode.com/problems/partition-array-for-maximum-sum/description/
//current subarray sum = length*maximum
//express everything as indx
//try every possible partition for that condition
//take best partition
//tc O(n)*O(k) sc O(n)+auxiliary stack space
using namespace std;

class Solution {
public:
    int f(int idx,vector<int>&num,int k){
        if(idx == num.size()) return 0;
        int n = num.size();
        int maxi = INT_MIN;
        int len = 0;
        int maxAns = INT_MIN;
        for(int j = idx;j < min(idx+k,n);++j){
            len++;
            maxi = max(maxi,num[j]);
            int sum = len*maxi + f(j+1,num,k);
            maxAns = max(maxAns,sum);
        }
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return f(0,arr,k);
    }
};