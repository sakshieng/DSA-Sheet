#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int miniUnfairness = INT_MAX;
    int distributeCookies(vector<int> &cookies, int k)
    {
        vector<int> bucket(k, 0);
        memo(cookies, k, cookies.size() - 1, miniUnfairness, bucket);
        return miniUnfairness;
    }
    void memo(vector<int> &cookies, int k, int i, int &mini, vector<int> &bucket)
    {
        int n = cookies.size();
        int maxi = *max_element(bucket.begin(), bucket.end());
        if (i < 0)
        {
            mini = min(mini, maxi);
            return;
        }
        if (i >= n)
        {
            return;
        }
        if (maxi > mini)
            return;
        // loop from 0 to k children assign cookies to all k children
        for (int idx = 0; idx < k; ++idx)
        {
            bucket[idx] += cookies[i];
            memo(cookies, k, i - 1, mini, bucket); // will backtrack to prev
            bucket[idx] -= cookies[i];             // minus from bckt
        }
        return;
    }
};
// TC->k^n optimize the approach using backtracking
int main(){
    Solution solution;
    vector<int>ans = {8,15,10,20,8};
    int finals = solution.distributeCookies(ans,2);
    cout<<finals;
}