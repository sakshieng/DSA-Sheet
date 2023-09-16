#include<bits/stdc++.h>
//https://leetcode.com/problems/valid-mountain-array/description/
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int maxi=0,idx=0,n=arr.size();
        for(int i=0;i<n;++i){
            //find peak elmt
            if(maxi < arr[i]){
                maxi = arr[i];
                idx = i;
            }
        }
        //idx->peak elmt cha idx so if this is at start / end then false
        if(idx==0 || idx==n-1) return 0;
        for(int i=0;i<idx-1;++i)
        //peak elmt chya left la ascending
            if(arr[i] >= arr[i+1])
                return 0;
        for(int i=n-1;i>idx;i--)
        //peak elmt chya right la descending 
            if(arr[i] >= arr[i-1])
                return 0;
        return 1;
    }
};