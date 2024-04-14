#include<bits/stdc++.h>
using namespace std;
// https://www.codingninjas.com/studio/problems/rotation_7449070?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=0

int findKRotation(vector<int> &arr){
    int lo=0,hi=arr.size()-1;
    int ans = INT_MAX,idx=-1;
    while(lo<=hi){
    int mid=(lo+hi)/2;    
    if(arr[lo] <= arr[hi]){
        if(arr[lo] < ans){
            idx=lo;
            ans = arr[lo];
        }
        break;
    }
    if(arr[lo] <= arr[mid]){
        if(arr[lo] < ans){
            idx=lo;
            ans = arr[lo];
        }
        lo=mid+1;
    }else{
        hi =mid -1;
        if(arr[mid] < ans){
            idx=mid;
            ans = arr[mid];
        }
    }
}
    return idx;
}
//TC O(logN) SC O(1)