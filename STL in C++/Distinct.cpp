#include <iostream>
#include <vector>
#include <unordered_set>
// finiding distinct elements of an array
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums) {
        unordered_set<int> distinctSet;
        int start = 0,end = nums.size()-1;
        for (int i = start; i <= end; i++) {
            distinctSet.insert(nums[i]);
        }
        return distinctSet.size();
    }

};

int main() {
    vector<int> nums = {1, 2, 2, 4, 5};
    Solution solution;
    int m = solution.countDistinct(nums);
    cout << m;
    return 0;
}
