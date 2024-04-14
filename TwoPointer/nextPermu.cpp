#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/next-permutation5226/1

class Solution{
public:


    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) swap(nums[i++], nums[j--]);
    }

    vector<int> nextPermutation(int n, vector<int> nums){
        
        if (n <= 1) return {};
        int i = n - 2;
        // find breakpoint can be at 2nd last idx
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            // if we get the breakpoint we will iterate again and if found lesser element, then swap it
            int j = n - 1;
            while (nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);
        }
        // for arr 1 2 3 4 5 next permutation will be 5 4 3 2 1
        // means we are reversing the right half
        reverse(nums, i + 1, n - 1);
        return nums;
    }
};

int main(){
    
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    
    return 0;
}
// n=3 arr={3,2,1} o/p={1,2,3}