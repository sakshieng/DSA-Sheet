// https://leetcode.com/problems/permutation-sequence/description/
#include<bits/stdc++.h>
//recursive solution O(n!*n)
//memo O(n^2) sc O(n)
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> nums;
        //find n-1th permutation
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string ans="";
        // empty string
        while(nums.size() != 0){
            int block=k/fact;
            ans=ans+to_string(nums[block]);
            nums.erase(nums.begin()+block);
            // syntax of vec.erase(vec.begin()+ind); ind to be deleted
            if(nums.size()==0){
                break;
            }
            // as we erase element from vector it may be chance that vec gets so empty so put codn here
            k=k%fact;
            fact=fact/nums.size();
        }
        return ans;
    }
};