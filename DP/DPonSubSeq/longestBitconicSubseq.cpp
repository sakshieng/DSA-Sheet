#include<bits/stdc++.h>
//https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&leftPanelTab=0
using namespace std;


int longestBitonicSubsequence(vector<int>& nums, int n)
{
	// LIS , longest decreasing subseq are bitconic too
	//combine lis from front & back u will get bitonic 
    vector<int>dp1(n,1);
    for(int i=0;i<n;++i){
        for(int prev=0;prev<i;++prev){
            if(nums[prev] < nums[i] && 1+dp1[prev] > dp1[i]){
                dp1[i] = 1+dp1[prev];
        	}
    	}
	}
    vector<int>dp2(n,1);
	for(int i=n-1;i>=0;i--){
		for(int prev=n-1;prev > i;prev--){
			if(nums[prev] < nums[i] && 1+dp2[prev] > dp2[i]){
				dp2[i] = 1+dp2[prev];
			}
		}
	}
	int maxi=0;
	for(int i=0;i<n;++i) maxi = max(maxi,dp1[i]+dp2[i]-1);
	return maxi;
}
