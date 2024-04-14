//prefix sum problem
#include<bits/stdc++.h>
//𝕊𝕒𝕜𝕤𝕙𝕚 ℂ𝕠𝕕𝕖𝕤 𝕙𝕖𝕣𝕖
using namespace std;
//https://leetcode.com/problems/ways-to-make-a-fair-array/description/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int>oddSum(n+1,0);
        vector<int>evenSum(n+1,0);
        for(int i=0;i<n;++i){
            if(i%2){
                //odd idx
                oddSum[i] += nums[i];
                if(i <= 1) oddSum[i] += 0;
                else oddSum[i] += oddSum[i-2];
                //update evensum
                evenSum[i] = evenSum[i-1];
            }else{
                evenSum[i] += nums[i];
                if(i <= 1) evenSum[i] += 0;
                else evenSum[i] += evenSum[i-2];
                if(i>0) oddSum[i]=oddSum[i-1];
            }
        }
        int cnt = 0;
        //check for every elmt odd and even sum are equal are not
        for(int i=0;i<n;++i){
            int odd=0,even=0;
            if(i%2){
                if(i<=1) odd=0;
                else odd=oddSum[i-2];
                odd += evenSum[n-1]-evenSum[i-1];
                even = evenSum[i-1];
                even += oddSum[n-1]-oddSum[i];
            }else{
                if(i <= 1) even = 0;
                else even = evenSum[i-2];
                if(i == 0) even += oddSum[n-1];
                else even += oddSum[n-1]-oddSum[i-1];
                if(i == 0) odd = 0;
                else odd = oddSum[i-1];
                odd += evenSum[n-1]-evenSum[i];
            }
            if(odd == even) cnt++;
        }
        return cnt;
    }
};
/*
take prefix sum odd idx and even idx
    6 1 7 1 4
odd:0 1 1 2 2
even:6 6 13 13 17
suppose we will update arr to
    1 7 1 4
odd:0 7 7 11
even:1 1 2 2 
then even becomes odd of prev and odd becomes even   
*/