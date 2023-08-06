// https://leetcode.com/problems/house-robber/description/

//print all subsequences by pick+nonPick here pick subseq which are non-adjacent means f(idx-2)
//if(idx==0) means i have picked idx 1 so return a[idx]
//tC->O(2^n) recursion
//f(1) means sum between [0...1] f(2) means sum between [0....2]
//for f(3) pick=9+f(1)=9+2=11 nonPick=0+f(2)=0+6=6 so max of them hence f(3)=11

#include <bits/stdc++.h> 
using namespace std;
//https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1;i<n;++i){
        int pick = nums[i];
        if(i >1) pick += prev2;
        int nonPick = 0+prev;
        int curr = max(pick,nonPick);
        prev2 = prev;
        prev = curr;
    }
   return prev;
}