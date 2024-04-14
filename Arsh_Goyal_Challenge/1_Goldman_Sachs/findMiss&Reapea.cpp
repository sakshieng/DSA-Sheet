//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xorr = 0;
        for (int i = 0; i < n; i++)
        {
            xorr = xorr^arr[i];
            xorr = xorr^(i+1);
        }
        int bitNo = 0;
        while (1)
        {
            if((xorr & (1<<bitNo)) != 0)
                break;
            bitNo++;
        }
        int zero = 0,one = 0;
        for (int i = 0; i < n; i++)
        {
            //part of 1 club
            if((arr[i] & (1<<bitNo)) != 0)
                one = one ^ arr[i];
            else
                zero = zero ^ arr[i];
        }
        for(int i = 1;i <= n;++i){
            if((i & (1<<bitNo)) != 0)
                one = one ^ i;
            else
                zero = zero ^ i;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == zero)
                cnt++;
        }
        if(cnt == 2) 
            return {zero,one};//repeating
        return {one,zero};
    }
};
