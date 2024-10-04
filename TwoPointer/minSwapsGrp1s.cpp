// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

class Solution {
public:
//no of swaps is no of 0's in subarray
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        int n = nums.size(),ans = n;
        for(auto &i:nums) ones += (i == 1);
        //to handle circular arr append arr as it is to back
        nums.insert(end(nums),begin(nums),end(nums));
        int i = 0,j = 0,oneTmp = 0;//window size equal to no of 1's
        while(j < 2*n){
            oneTmp += (nums[j] == 1);
            if(j-i+1 == ones){
                ans = min(ans,ones-oneTmp);
                oneTmp -= (nums[i] == 1);
                i++;
            }
            j++;
        }
        return ans == n ? 0 : ans;
    }
};
int main(){
    cerr << "jellpo";
    return 0;
}