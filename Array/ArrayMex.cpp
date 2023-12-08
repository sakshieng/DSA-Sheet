#include<bits/stdc++.h>
//https://csacademy.com/contest/interview-archive/task/array-mex/statement/
using namespace std;

int mex(vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        while (nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
            swap(nums[i], nums[nums[i]]);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i) {
            return i;
        }
    }
    
    return n;
}
int main() {
    int N;
    cin >> N;
    
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    
    cout << mex(v) << "\n";
    return 0;
}
