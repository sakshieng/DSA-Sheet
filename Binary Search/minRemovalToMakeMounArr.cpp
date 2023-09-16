#include<bits/stdc++.h>
//https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
using namespace std;

/*LIS LDS when LIS and LDS are 1 discard that

2 1 1 5 6 2 3 1
1 1 1 2 3 2 3 2<-LIS
2 1 1 3 3 2 2 1<-LDS
for LDS look to right if there is elmt which is lower
*/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);

        //LIS from left to right
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        //LDS from right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        int maxMountain = 0;

        // Find the maximum mountain length
        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxMountain = max(maxMountain, lis[i] + lds[i] - 1);
            }
        }

        return n - maxMountain;
    }
};
