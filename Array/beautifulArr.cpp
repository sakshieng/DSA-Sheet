#include<bits/stdc++.h>
//https://leetcode.com/problems/beautiful-array/
using namespace std;
//odd even pattern
class Solution {
public:
//no direct approach try divide & conquer no k such that a[k]*2 = odd+even
//a1 = a*2-1 ->true when odds from 1 to n*2-1 
//a2 = a*2 ->true when even form 2 to n*2
//b = a1+a2 ->true when length = n*2
    vector<int> beautifulArray(int n) {
        vector<int>res = {1};
        while(res.size() < n){
            vector<int>tmp;
            for(int i:res)
                if(i*2-1 <= n)
                    tmp.push_back(i*2-1);
            for(int i:res)
                if(i*2 <= n)
                    tmp.push_back(i*2);
            res = tmp;
        }
        return res;
    }
};