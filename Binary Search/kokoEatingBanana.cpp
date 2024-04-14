#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
/*
simple linear search will give TC->O(max_elmt*n) which will give TLE
so for finding max elmt in arr we will use binary search 
for BS TC is reduced to O(n)*log2(max_elmt)
*/
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

long long calculateTotalHours(vector<int> &v, int hrs) {
    long long totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += (v[i] + hrs - 1) / hrs; 
    }
    return totalH;
}

    int minEatingSpeed(vector<int>& v, int h) {
     int low = 1, high = findMax(v);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        long long totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
    }
};
