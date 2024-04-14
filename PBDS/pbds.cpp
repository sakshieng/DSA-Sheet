#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
// sakshi codes here
using namespace std;

// https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/
using namespace __gnu_pbds;
// as we have duplicate elmts in arr so use multi pbds like multiset
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        pbds a;
        vector<int> a1, a2;
        pbds b;
        a1.push_back(nums[0]);
        a.insert(nums[0]);
        a2.push_back(nums[1]);
        b.insert(nums[1]);

        for (int i = 2; i < nums.size(); ++i)
        {
            int totalElmtInA = a.size();
            int g1 = totalElmtInA - a.order_of_key(nums[i] + 1);
            int totalElmtInB = b.size();
            int g2 = totalElmtInB - b.order_of_key(nums[i] + 1);

            if (g1 > g2)
            {
                a1.push_back(nums[i]);
                a.insert(nums[i]);
            }
            else if (g2 > g1)
            {
                a2.push_back(nums[i]);
                b.insert(nums[i]);
            }
            else
            {
                if (a.size() > b.size())
                {
                    a2.push_back(nums[i]);
                    b.insert(nums[i]);
                }
                else
                {
                    a1.push_back(nums[i]);
                    a.insert(nums[i]);
                }
            }
        }
        vector<int> res;
        for (int &i : a1)
            res.push_back(i);
        for (int &i : a2)
            res.push_back(i);
        return res;
    }
    
};