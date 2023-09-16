#include<bits/stdc++.h>
//https://leetcode.com/problems/longest-mountain-in-array/description/
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        //peak point defines the mountain
        int n = arr.size();
        //loop from 1 to n-2
        int cnt = 0,maxi = 0;
        for(int i=1;i<=n-2;++i){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])//check with neighbours
            {
                int idx = i;
                //check to left
                cnt = 1;//for mid elmt
                while(idx > 0 and arr[idx]>arr[idx-1]){
                    //mean we are still traversing in mountain
                    idx--;
                    cnt++;
                }
                while(i<n-1 and arr[i]>arr[i+1]){
                    i++;
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};