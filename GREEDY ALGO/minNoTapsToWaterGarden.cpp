#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
// https://www.geeksforgeeks.org/count-minimum-number-of-fountains-to-be-activated-to-cover-the-entire-garden/
using namespace std;

class Solution {
public:
const int mod = 1e9;
    int minTaps(int n, vector<int>& ranges) {
        //pre-compute for every left point 
        vector<int>arr(n+1,mod);
        arr[0] = 0;

        for(int i=0;i<ranges.size();++i){
           
            int mini = max(0,i-ranges[i]);
            int maxi = min(n,i+ranges[i]);

            for(int j=mini;j < maxi;j++){
                arr[maxi] = min(arr[maxi],arr[j]+1);
            }
        }
        return arr[n] == mod ? -1 : arr[n];
    }
};

//greedy approach take max ranges for evaluation
