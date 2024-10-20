#include <bits/stdc++.h>
// https://leetcode.com/problems/find-unique-binary-string/description/
using namespace std;
// hint is ki we can convert convert str to 10 base integer and then if we want unique str of len-2 then we would return the integer which is not in nums
// store the equivalent integers in hashset
// sometime when converted binary str has len<n then add "0" in beginning
class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        // this que we are generating new diff str which is not in array of str
        //  Cantor's diagonal argument
        int n = nums.size();
        string ans(n, '0');

        for (int i = 0; i < n; ++i)
        {
            ans[i] = (nums[i][i] == '0') ? '1' : '0';
        }

        return ans;
    }

    // if((orr & (orr + 1)) == 0) this will give u if orr+1 has all set bits or not
};
