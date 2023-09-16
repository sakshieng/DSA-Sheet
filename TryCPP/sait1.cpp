#include<bits/stdc++.h>
//sakshi codes here
using namespace std;

int searchInsertPosition(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, target;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        cin >> target;

        int result = searchInsertPosition(nums, target);
        cout << result << endl;
    }

    return 0;
}
