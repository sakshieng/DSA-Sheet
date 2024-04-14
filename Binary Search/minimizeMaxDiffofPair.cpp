#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

class Solution {
public:
bool isValid(vector<int>& a,int mid,int p){
    int cnt = 0;
    for (int i = 0; i < a.size() - 1 && cnt < p;){
        if(a[i+1]-a[i] <= mid){
            cnt++;
            i += 2;
        }else{
            i++;
        }
    }
    return cnt>=p;
}
    int minimizeMax(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        int lo=0,hi=a.back()-a.front();
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(isValid(a,mid,p)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};