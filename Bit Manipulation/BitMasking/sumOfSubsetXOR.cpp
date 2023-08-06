#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
// bit masking 
        int cnt =0;
        int n = nums.size();
        for(int i=0;i<1<<n;++i){
            int total=0;
            for(int j=0;j<n;++j){
                if((i & 1<<j) > 0){
                    total = total ^ nums[j];
                }
            }
            cnt += total;
        }
        return cnt;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5};
    int result = solution.subsetXORSum(nums);
    cout << "Subset XOR Sum: " << result << endl;
    
    return 0;
}