#include <bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// space optimization when we see idx-1 at line 15 
//TC->O(n*target)+O(n){for calculating totalSum} SC->O(target)  no idx array
bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<bool> prev(k+1,0),curr(k+1,0);

    prev[0] = curr[0] = true;
   if(arr[0]<=k) prev[arr[0]] = true; // as base case when target is 0 at a[0] then it is accepted
    for (int idx = 1; idx < n; ++idx)
    {
        for (int target=1;target<=k;++target){
           bool nonPick = prev[target];
           bool pick = false; 
           if (target >= arr[idx]){
            pick = prev[target-arr[idx]];
           }
            curr[target] = pick || nonPick;
        }
        prev = curr;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
	int totalSum = 0;
	for(int i=0;i<n;++i) totalSum += arr[i];
	int target = totalSum/2;
	if(totalSum%2 != 0) return false;
	return subsetSumToK(n,target,arr);

}