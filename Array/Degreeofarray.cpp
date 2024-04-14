#include <bits/stdc++.h>
/* Sakshi */
using namespace std;
/*
[1 2 2 3 1]

1 2
2 2
3 1

1 2
2 2
3 1

1,2-->k
0 1 2 3 4 -->ind
1 2 2 3 1
i        j

for k=1
v[0]=j-i+1=4-0+1=5


0 1 2 3 4 -->ind
1 2 2 3 1
  i  j
for k=2
v[1]=2-1+1=2

so minimum of 5 and 2 is 2
*/

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    //       basically we have to written mini sized subarray which have freqn same as that of given
    int findShortestSubArray(vector<int> &nums)
    {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int, int>> vp;
        // this vector of pair stores the element which have max frequen
        for (auto &&i : m)
        {
            vp.push_back({i.first, i.second});
        }
        sort(vp.begin(), vp.end(), cmp);
        vector<int> v;
        for (auto &&i : vp)
        {
            if (i.second == vp[0].second)
            {
                v.push_back(i.first);
            }
        }
        int mini = INT_MAX;
        int k = 0;
        int n = v.size();
        while (k < n)
        {
            int i = 0, j = nums.size() - 1;
            while (1)
            {

                if (nums[i] != v[k])
                {
                    i++;
                }
                if (nums[j] != v[k])
                {
                    j--;
                }
                if (nums[i] == v[k] && nums[j] == v[k])
                    break;
            }
            k++;
            mini = min(mini, j - i + 1);
        }
        return mini;
    }
};
int main() {
    Solution solution;
    vector<int>ans = {1,2,2,4,2,3,1};
    int result = solution.findShortestSubArray(ans);
    cout << "Size subarrays: " << result << endl;
    
    return 0;
}