#include<bits/stdc++.h>
//sakshi codes here
using namespace std;
//ask to P_Shah
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));//as we need max elmt 
        long long i=0,j=0,sum=0,ans=0;
        for( i=0;i < nums.size();++i){
            sum += nums[i];//calculate running sum 
            while((i-j+1)*nums[i] - sum > k)//loop until the window is valid
            {
                sum -= nums[j];
                j++;
            }
            ans = max(ans,i-j+1);//size of window will be the freqn of elmt
        }
        return ans;
    }
};