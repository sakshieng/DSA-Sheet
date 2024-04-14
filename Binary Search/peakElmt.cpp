// https://leetcode.com/problems/peak-index-in-a-mountain-array/
// https://www.codingninjas.com/studio/problems/find-peak-element_1081482?leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0,high = arr.size()-1;
        int ans = 0;
        while(low<high){
            int mid = low+(high-low)/2;
            if(arr[mid] > arr[mid+1]){
                ans = mid;
                high = mid;
            }else{
                if(arr[mid] <= arr[mid+1]){
                    ans = mid+1;
                    low = mid+1;
                }
            }
        }
        return ans;
    }
};