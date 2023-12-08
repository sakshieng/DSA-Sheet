#include<bits/stdc++.h>
using namespace std;
// kadanes algorithm
// https://www.codingninjas.com/studio/problems/maximum-subarray-sum_628288?leftPanelTab=0
// https://leetcode.com/problems/maximum-subarray/description/
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = 0;
    long long sum =0;
    for(long long int i=0;i<n;++i){
        sum += arr[i];
        maxi = max(sum,maxi);
        if(sum<0) sum = 0;
    }
    return maxi;
}
int main() {
int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int maxSum = maxSubarraySum(arr, n);
	cout<<maxSum;

	return 0;
}