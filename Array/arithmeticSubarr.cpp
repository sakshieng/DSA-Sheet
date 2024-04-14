#include<bits/stdc++.h>
//https://leetcode.com/problems/arithmetic-subarrays/submissions/1104890995/?envType=daily-question&envId=2023-11-23
using namespace std;

class Solution {
public:
//2nd approach without sorting
bool solve(vector<int>&arr){
    int n = arr.size();
    int minE = INT_MAX;
    int maxE = INT_MIN;
    unordered_set<int>st;
    for(int &num:arr){
        minE = min(minE,num);
        maxE = max(maxE,num);
        st.insert(num);
    }
    //no divisible then why to calculate common diff
    if((maxE-minE)%(n-1) != 0)
        return 0;
    int diff = (maxE-minE)%(n-1);
    int curr = minE;
    while(curr < maxE)
    {
        if(st.find(curr) == st.end())//no exist in set
            return 0;
        curr += diff;//curr curr+d curr+2d curr+3d is the AP
    }
    return 1;
}
//tc O(m*nlogn) m->queries nlogn->sorting sc O(n)
bool check(vector<int>&arr){
    sort(begin(arr),end(arr));
    int diff = arr[1] - arr[0];
    for(int i=2;i<arr.size();++i)
        if(arr[i]-arr[i-1] != diff)
            return 0;
    return 1;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool>result;
        for (int i = 0; i < m; i++)
        {
            int start = l[i];
            int end = r[i];
            //we are pushing start to end elmts in subarray arr
            vector<int>arr(nums.begin()+start,nums.begin()+end+1);
            bool isAP = check(arr);
            result.push_back(isAP);

        }
        return result;
    }
};