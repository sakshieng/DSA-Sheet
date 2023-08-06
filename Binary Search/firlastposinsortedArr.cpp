#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution
{
public:
    //   in que for first element in ans take lower bound and for second take upper it will give address of greater value
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        auto low = lower_bound(nums.begin(),nums.end(),target);
//   in que for first element in ans take lower bound and for second take upper it will give address of greater value

        auto up = upper_bound(nums.begin(),nums.end(),target);
//upper bound func address detety as aapn address pass krtoy so we have to derefernce it which will give us value at t
        
        if(low == nums.end() || *low != target)    return {-1,-1};
        
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        return {first,last};
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 3, 3, 4, 5};
    int target = 3;
    vector<int> result = solution.searchRange(nums, target);
    cout << "First and Last Occurrence: " << result[0] << ", " << result[1] << endl;

    return 0;
}