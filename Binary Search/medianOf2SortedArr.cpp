#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //typecasting as ans is in double
    vector<int>arr;
    int i=0,j=0;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] < nums2[j]){
            arr.push_back(nums1[i++]);
        }
        else   arr.push_back(nums2[j++]);
    }
    while(i<nums1.size()) arr.push_back(nums1[i++]);
    while(j<nums2.size()) arr.push_back(nums2[j++]);
    int n = nums1.size() + nums2.size();
    if(n%2 == 1) return arr[n/2];
    return (double)((double)(arr[n/2])+(double)(arr[n/2-1]))/2.0;
    }
};