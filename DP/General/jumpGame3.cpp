#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

// https://leetcode.com/problems/jump-game-iii/
class Solution {
public:
    
    bool check = false;
    
    int solve(vector<int> &dp, vector<int> &arr, int index)
    {
        // cout << index << endl;
        if(index < 0 || index >= arr.size()) return 0;
        
        if(arr[index] == 0)
        {
            check = true;
            return 1;
        }
        
        if(check == true) return 1;
        if(dp[index] != -1) return 0;
        
        dp[index] = 0;
        
        return dp[index] = solve(dp, arr, index+arr[index]) || solve(dp, arr, index-arr[index]);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        vector<int> dp(arr.size()+1, -1);
        return solve(dp, arr, start);
    }
};
//jo idx visit kelay tyala parat visit nhi kryche